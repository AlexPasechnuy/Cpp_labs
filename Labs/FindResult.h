#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <conio.h>
#include <fstream>

using namespace std;

class FindResult
{
private:
	int x;
	int n;
	int a;
	int sum;
	struct Cord
	{
		int _x;		//>
		int _y;		//^
	};
	vector<string> giveMenu = {"Give from file", "Give from keyboard", ""};
	vector<string> is = { "Yes", "No", "" };
	bool isExit = false;
public:
	void getData();
	void getFromFile();
	void positiveX();
	void negativeX();
	void show();
	void returnToFile();
	int movePointer();
	void cursorPositionSet(const Cord & cord);
	int menuOrgan(vector<string>);
	void useClass();
};

void FindResult::useClass()
{

}

void FindResult::cursorPositionSet(const Cord & cord)
{
	static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { cord._x, cord._y };
	SetConsoleCursorPosition(hConsole, position);
}

int FindResult::movePointer()
{
	bool exit = false;
	int ch;

	Cord cord = { 0, 0 };

	while (!exit)
	{
		ch = _getch();
		if (ch == 224)
			ch = _getch();
		switch (ch)
		{
		case 13:	exit = true;	break;	//нажата клавиша Enter
		case 27:	return -1;		break;	//нажата клавиша Esc
		default:
		{
			switch (ch)
			{
			case 72:	
				
				cord._y--;	break;// нажата клавиша вверх
			case 80:	
				
				cord._y++;	break;// нажата клавиша вниз
			}
			cursorPositionSet(cord);
			break;
		}
		}
	}
	system("cls");
	return cord._y;
};

int FindResult::menuOrgan(vector<string> menu)
{
	for (int i = 0; menu[i] != ""; i++)
	{
		cout << menu[i] << '\n';
	}
	return movePointer();
};

void FindResult::getData()
{
	cout << "Select data input way please:\n";
	system("cls");
	switch (menuOrgan(giveMenu))
	{
	case 1:
		void getFromFile();
		break;
	case 2:
		cout << "Enter your variables:\nx = ";
		cin >> x;
		cout << "\nn = ";
		cin >> n;
		break;
	}
}

void FindResult::getFromFile()
{

}

void FindResult::returnToFile()
{

}

void FindResult::positiveX()
{

}

void FindResult::negativeX()
{

}


void FindResult::show()
{
	cout << "Your result is " << sum << endl
		<< "Do you want to save it to the file?";
	switch (menuOrgan(is))
	{
	case 2:
		void returnToFile();
		break;
	case 3:
		break;
	}

	system("cls");
	cout << "Do you want to use the program again?";
	switch (menuOrgan(is))
	{
	case 1:
		break;
	case 2:
		isExit = true;
		cout << "Thanks for using my product)";
		break;
	}
}