#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "tools.h"

class Lab2
{
private:
	double n;
	double stepSize;
	double x;
	double maxX;
	double sum;
	std::vector<double> results;
	std::vector<std::vector<double>> data;
	std::vector<std::string> strVec;
	std::string filename;
public:
	bool getData();
	void useLab2();
	void calculations();
	bool fileWork();
	void getFromFile();
	void getFromKeyboard();
	void returnToFile();
	void positiveX();
	void negativeX();
	void openFiles();
	void openBasic();
	void openOther();
	void fillFiles();
	void createFile();
	bool checkFile(std::string);
};

void Lab2::useLab2()
{
	bool isExit = false;
		if (getData() == false)
			return;
		calculations();
		returnToFile();
		system("cls");
}

void Lab2::calculations()
{
	for (x; x <= maxX; x += stepSize)
	{
		if (x >= 0)
			positiveX();
		else
			negativeX();
		std::cout << "x = " << x << "; sum = " << sum << std::endl;
		results.push_back(sum);
	}
}

bool Lab2::getData()
{
	bool isExit = false;
	while (isExit == false)
	{
		std::cout << "Select data input way please:\n";
		std::vector<std::string> giveMenu = { "Give from file", "Give from keyboard" };
		switch (Menu::getInstance().menuOrgan(giveMenu))
		{
		case -1:
			return false;
			break;
		case 0:
			isExit = fileWork();
			break;
		case 1:
			getFromKeyboard();
			isExit = true;
			break;
		}
		system("cls");
	}
	return true;
}

bool Lab2::fileWork()
{
	while (true)
	{
		system("cls");
		switch (Menu::getInstance().menuOrgan({ "Open file", "Create file" }))
		{
		case -1:
			return false;
			break;
		case 0:
			openFiles();
			break;
		case 1:
			createFile();
			break;
		}
	}
	getFromFile();
	while (true)
	{
		system("cls");
		std::cout << "Select your start and maximum value of x ,n and step size:\n";
		int choise = Menu::getInstance().menuOrgan(strVec);
		std::vector<double> vecDob = data[choise];
		x = vecDob[0];	//interval start
		maxX = vecDob[1];	//interval end
		n = vecDob[2];
		stepSize = vecDob[3];

		int minN;
		if (x < 0)
			minN = 2;
		else
			minN = 1;
		if (maxX >= x && stepSize > 0 && n >= minN)
			return true;
		if (maxX < x)
			std::cout << "!Your interval has negative direction!" << std::endl;
		if (stepSize <= 0)
			std::cout << "!Incorrect step size!" << std::endl;
		if (n < minN)
			std::cout << "!Your n is too small for this x!" << std::endl;
		system("pause");
	}
}

void Lab2::getFromFile()
{
	std::ifstream fin;
	fin.open(filename);
	int memb;
	strVec.clear();
	while (!fin.eof())
	{
		std::string str;
		std::vector<double> vecDob;

		for (int i = 0; i < 4; i++)
		{
			fin >> memb;
			vecDob.push_back(memb);
			str += std::to_string(memb) + " ";
		}

		strVec.push_back(str);
		data.push_back(vecDob);
	}
	fin.close();
}

void Lab2::openFiles()
{
	while (true)
	{
		std::cout << "Open basic file or select directory?:" << std::endl;
		switch (Menu::getInstance().menuOrgan({ "Basic file", "Select directory" }))
		{
		case -1:
			return;
			break;
		case 0:
			openBasic();
			break;
		case 1:
			openOther();
			break;
		}
	}
}

void Lab2::openBasic()
{
	while (true)
	{
		filename = "InputLab2.txt";
		std::ifstream fin;
		fin.open(filename);
		if (fin.is_open() == true)
			break;
		std::cout << "Basic file not found! Choose your own file or create new" << std::endl;
		system("pause");
	}
	//offer to fill file if it's empty
}

void Lab2::openOther()
{
	std::string path;
	std::cout << "Enter full path to your file:";
	std::getline (std::cin, path);
	std::ifstream fin;
	fin.open(path);
	if (fin.is_open() == false)
	{
		if (checkFile(path) == true)
		{
			
			std::cout << "Work with custom file";
			return;
		}
	}
	std::cout << "Can't find this file!" << std::endl 
		<< "Tap 'esc' to exit or another button to try again" << std::endl;
	int ch = _getch();
	if( ch == 27)
		return;
}

void Lab2::fillFiles()
{

}

void Lab2::createFile()
{
	std::string filename;
	while (true)
	{
		std::cout << "Enter full path of file or write only name to create in basic directory:" << std::endl;
		std::cin >> filename;
		std::ifstream checkPlace;
		std::ofstream create;
		std::ifstream checkFile;
		checkPlace.open(filename);
		if (checkPlace.is_open() == true)
		{
			std::cout << "This file already created!" << std::endl
				<< "Please, try again!" << std::endl;
		}
		else
		{
			create.open(filename);
			checkFile.open(filename);
			if (!checkFile.is_open())
			{
				std::cout << "Failed to create file!" << std::endl
					<< "Please, try again!" << std::endl;
			}
			else
			{
				std::cout << "File created!" << std::endl;
				checkPlace.close();
				create.close();
				checkFile.close();
				return;
			}
		}
	}
}

bool Lab2::checkFile(std::string filename)
{
	return true;
}

void Lab2::getFromKeyboard()
{
	while (true)
	{
		input("start value of your x :", x);
		input("maximum value of your x :", maxX);
		if (x <= maxX)
			break;
		std::cout << "Incorrect input: interval must have positive direction!" << std::endl;
	}
	while (true)
	{
		input("step = ", stepSize);
		if (stepSize > 0)
			break;
		std::cout << "Incorrect input: step must be greater than 0!" << std::endl;
	}
	int minN;
	if (x < 0)
		minN = 2;
	else
		minN = 1;
	while (true)
	{
		input("n = ", n);
		if (n >= minN)
			break;
		std::cout << "This n is too small for your x!" << std::endl;
	}
}

void Lab2::positiveX()
{
	sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += (x - 1) / (i + 1);
	}
}

void Lab2::negativeX()
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

void Lab2::returnToFile()
{
	std::ofstream fout;
	fout.open("OutputLab2.txt", std::ios_base::app);
	std::cout << std::endl << "Do you want to save your results to file?" << std::endl;
	switch (Menu::getInstance().menuOrgan({ "Yes", "No" }))
	{
	case 0:
		for (int i = 0; i < results.size(); i++)
		{
			fout << results[i] << " ";
		}
		fout << std::endl;
		fout.close();
		break;
	case 1:
		break;
	}
}