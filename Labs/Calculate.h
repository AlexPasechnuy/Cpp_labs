#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <cmath>

using namespace std;

class FindResult
{
private:
	double x;
	double n;
	double sum;
	struct Cord
	{
		int _x;		//>
		int _y;		//^
	};
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
	while (isExit == false)
	{
		getData();
		if (x >= 0)
			positiveX();
		else
			negativeX();
		show();
	}
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
	vector<string> giveMenu = { "Give from file", "Give from keyboard", "" };
	switch (menuOrgan(giveMenu))
	{
	case 1:
		getFromFile();
		break;
	case 2:
		cout << "Enter your variables:\nx = ";
		cin >> x;
		cout << "n = ";
		cin >> n;
		break;
	}
	system("cls");
}

void FindResult::getFromFile()
{
	ifstream fin;
	fin.open("Input.txt");
	vector<vector<double>> data;
	vector<double> vecDob;

	vector<string> strVec;

	int memb;
	while (!fin.eof())
	{
		for (int i = 0; i < 2; i++)
		{
			fin >> memb;
			vecDob.push_back(memb);
		}
		string str(vecDob.begin(), vecDob.end());
		strVec.push_back(str);
		data.push_back(vecDob);
	}
	cout << "Select your x and n\n";
	int choise = menuOrgan(strVec) - 1;
	vecDob = data[choise];
	x = vecDob[0];
	n = vecDob[1];
	fin.close();
}

void FindResult::returnToFile()
{
	ofstream fout;
	fout.open("Output.txt");
	fout << sum << endl;
	fout.close();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void FindResult::positiveX()
{
	for (int i = 0; i < n; i++)
	{
		sum += (x - 1) / (i + 1);
	}
}

void FindResult::negativeX()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			sum += x - (i*i) + j;
		}
	}
}


void FindResult::show()
{
	vector<string> is = { "Yes", "No", "" };
	cout << "Your result is " << sum << endl
		<< "Do you want to save it to the file?\n";
	switch (menuOrgan(is))
	{
	case 2:
		returnToFile();
		break;
	case 3:
		break;
	}

	system("cls");
	cout << "Do you want to use the program again?\n";
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