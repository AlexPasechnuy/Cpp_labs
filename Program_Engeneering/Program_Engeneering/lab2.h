#include <iostream>
#include <string>
#include <vector>
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
	bool isExit = false;
	std::vector<std::vector<double>> data;
	std::vector<std::string> strVec;
public:
	void getData();
	void useLab2();
	void fileWork();
	void getFromFile();
	void getFromKeyboard();
	void returnToFile();
	void positiveX();
	void negativeX();
};

void Lab2::useLab2()
{
	while (isExit == false)
	{
		getData();
		for (x; x <= maxX; x += stepSize)
		{
			if (x >= 0)
				positiveX();
			else
				negativeX();
			std::cout << "x = " << x << "; sum = " << sum << std::endl;
			results.push_back(sum);
		}
		returnToFile();
		system("cls");
		std::cout << "Do you want to use the program again?\n";
		switch (Menu::getInstance().menuOrgan({ "Yes", "No" }))
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
}

void Lab2::getData()
{
	std::cout << "Select data input way please:\n";
	std::vector<std::string> giveMenu = { "Give from file", "Give from keyboard" };
	switch (Menu::getInstance().menuOrgan(giveMenu))
	{
	case 0:
		fileWork();
		break;
	case 1:
		getFromKeyboard();
		break;
	}
	system("cls");
}

void Lab2::fileWork()
{
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
			return;
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
	fin.open("InputLab2.txt");
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