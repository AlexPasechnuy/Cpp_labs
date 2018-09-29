#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>

#include "Menu.h"

class Lab1
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
	void useLab1();
};

void Lab1::useLab1()
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


void Lab1::getData()
{
	std::cout << "Select data input way please:\n";
	std::vector<std::string> giveMenu = { "Give from file", "Give from keyboard"};
	switch (Menu::getInstance().menuOrgan(giveMenu))
	{
	case 0:
		getFromFile();
		break;
	case 1:
		std::cout << "Enter your variables:\nx = ";
		std::cin >> x;
		std::cout << "n = ";
		std::cin >> n;
		break;
	}
	system("cls");
}

void Lab1::getFromFile()
{
	std::ifstream fin;
	fin.open("InputLab1.txt");
	std::vector<std::vector<double>> data;
	

	std::vector<std::string> strVec;

	int memb;
	while (!fin.eof())
	{
		std::string str;
		std::vector<double> vecDob;

		for (int i = 0; i < 2; i++)
		{
			fin >> memb;
			vecDob.push_back(memb);
			str += std::to_string(memb) + " ";
		}
		
		strVec.push_back(str);
		data.push_back(vecDob);
	}
	std::cout << "Select your x and n\n";

	int choise = Menu::getInstance().menuOrgan(strVec);
	std::vector<double> vecDob = data[choise];
	x = vecDob[0];
	n = vecDob[1];
	fin.close();
}

void Lab1::returnToFile()
{
	std::ofstream fout;
	fout.open("OutputLab1.txt", std::ios_base::app);
	fout << sum << std::endl;
	fout.close();

}


void Lab1::positiveX()
{
	sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += (x - 1) / (i + 1);
	}
}

void Lab1::negativeX()
{
	sum = 0;
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			sum += x - (i*i) + j;
		}
	}
}


void Lab1::show()
{
	std::vector<std::string> is = { "Yes", "No"};
	std::cout << "Your result is " << sum << std::endl
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
	std::cout << "Do you want to use the program again?\n";
	switch (Menu::getInstance().menuOrgan(is))
	{
	case 0:
		break;
	case 1:
		isExit = true;
		std::cout << "Thanks for using my product)\n"
		<< "With love, Alex Pasechnuy\n";
		break;
	}
}