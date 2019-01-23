#pragma once

#include "tools.h"

class Menu{

private:

	HANDLE hConsole;

	struct Cord
	{
		int _x;		//>
		int _y;		//^
	};

	void Menu::cursorPositionSet(const Cord & cord)
	{
		COORD position = { cord._x, cord._y };
		SetConsoleCursorPosition(hConsole, position);
	}

	Cord Menu::cursorPositionGet()
	{
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(hConsole, &csbi);
		return{ csbi.dwCursorPosition.X, csbi.dwCursorPosition.Y };
	}

	int Menu::movePointer(Cord begin)
	{
		bool exit = false;
		Cord end = cursorPositionGet();
		end._y--;
		Cord cord = begin;
		cursorPositionSet(begin);


		while (!exit)
		{
			int ch = _getch();
			if (ch == 224)
				ch = _getch();

			switch (ch)
			{
			case 13:
				exit = true;
				break;			//нажата клавиша Enter
			case 27:
				return -1;		//нажата клавиша Esc
			case 72:			// нажата клавиша вверх
				if (cord._y > begin._y)
					cord._y--;
				cursorPositionSet(cord);
				break;
			case 80:			// нажата клавиша вниз
				if (cord._y < end._y)
					cord._y++;
				cursorPositionSet(cord);
				break;
			}
		}
		system("cls");
		return cord._y - begin._y;
	};

	Menu(){
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	};

public:

	static Menu& getInstance()	//Singleton
	{
		static Menu menu;
		return menu;
	};

	int Menu::menuOrgan(std::vector<std::string> menu)
	{
		Cord cord = cursorPositionGet();
		for (std::string str : menu)
		{
			std::cout << str << '\n';
		}
		return movePointer(cord);
	}
};