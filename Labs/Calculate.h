#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>

#include "Menu.h"

using namespace std;

class FindResult
{
private:
	double x;
	double n;
	double sum;
	
	bool isExit = false;
public:
	void getData();
	void getFromFile();
	void positiveX();
	void negativeX();
	void show();
	void returnToFile();
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


void FindResult::getData()
{
	cout << "Select data input way please:\n";
	vector<string> giveMenu = { "Give from file", "Give from keyboard"};
	switch (Menu::getInstance().menuOrgan(giveMenu))
	{
	case 0:
		getFromFile();
		break;
	case 1:
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
	

	vector<string> strVec;

	int memb;
	while (!fin.eof())
	{
		string str;
		vector<double> vecDob;

		for (int i = 0; i < 2; i++)
		{
			fin >> memb;
			vecDob.push_back(memb);
			str += to_string(memb) + " ";
		}
		
		strVec.push_back(str);
		data.push_back(vecDob);
	}
	cout << "Select your x and n\n";

	int choise = Menu::getInstance().menuOrgan(strVec);
	vector<double> vecDob = data[choise];
	x = vecDob[0];
	n = vecDob[1];
	fin.close();
}

void FindResult::returnToFile()
{
	ofstream fout;
	fout.open("Output.txt", ios_base::app);
	fout << sum << endl;
	fout.close();
}

void FindResult::positiveX()
{
	sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += (x - 1) / (i + 1);
	}
}

void FindResult::negativeX()
{
	sum = 0;
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
	vector<string> is = { "Yes", "No"};
	cout << "Your result is " << sum << endl
		<< "Do you want to save it to the file?\n";
	switch (Menu::getInstance().menuOrgan(is))
	{
	case 0:
		returnToFile();
		break;
	case 1:
		break;
	}

	system("cls");
	cout << "Do you want to use the program again?\n";
	switch (Menu::getInstance().menuOrgan(is))
	{
	case 0:
		break;
	case 1:
		isExit = true;
		cout << "Thanks for using my product)\n"
		<< "With love, Alex Pasechnuy\n";
		break;
	}
}