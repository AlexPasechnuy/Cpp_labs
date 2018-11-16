#pragma once

#include "Tools.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>

#include "Menu.h"

class MaxMin
{
private:
	std::vector<double> vec;
public:
	void inputVec()
	{
		while (true)
		{
			double a;
			input("Enter new number:" , a);
			vec.push_back(a);
				std::cout << "\nTap 'esc' to exit, or another key to continue!" << std::endl;
			int ch = _getch();
			if (ch == 27)
				break;
		}
	}

	double maxVal(std::vector<double> vec)
	{
		double max = vec[0];
		for (int i = 1; i < vec.size(); i++)
		{
			if (vec[i] > max)
				max = vec[i];
		}
		return max;
	}

	double minVal(std::vector<double> vec)
	{
		double min = vec[0];
		for (int i = 1; i < vec.size(); i++)
		{
			if (vec[i] < min)
				min = vec[i];
		}
		return min;
	}

	void useFunc()
	{
		inputVec();
		std::cout << "Your sum is " << minVal(vec) + maxVal(vec) << std::endl;
		system("pause");
	}
};

class Sort
{
public:
	std::vector<int> inputVec()
	{
		std::vector<int> vec;
		while (true)
		{
			int a;
			input("Enter new number:", a);
			vec.push_back(a);
			std::cout << "\nTap 'esc' to exit, or another key to continue!" << std::endl;
			int ch = _getch();
			if (ch == 27)
				break;
		}
		return vec;
	}

	std::vector<int> sortVec(std::vector<int> vec)
	{
		int temp; // временная переменная для обмена элементов местами

		// Сортировка массива пузырьком
		for (int i = 0; i < vec.size() - 1; i++) {
			for (int j = 0; j < vec.size() - i - 1; j++) {
				if (vec[j] > vec[j + 1]) {
					// меняем элементы местами
					temp = vec[j];
					vec[j] = vec[j + 1];
					vec[j + 1] = temp;
				}
			}
		}
		return vec;
	}

	void outputVec(std::vector<int> vec)
	{
		for (int i = 0; i < vec.size(); i++)
		{
			std::cout << vec[i] << ' ';
		}
		std::cout << std::endl;
	}

	void useSort()
	{
		std::vector<int> vec = inputVec();
		vec = sortVec(vec);
		outputVec(vec);
		system("pause");
	}
};

class SumPos
{
private:

public:
	std::vector<std::vector<int>> dblVecInput()
	{
		std::vector<std::vector<int>> dblVec;
		std::vector<int> vec;
		int rows;
		int cllmns;
		input("Enter amount of rows:", rows);
		input ("Enter amount of collumns:", cllmns);
		for (int i = 0; i < rows; i++)
		{
			for (int i = 0; i < cllmns; i++)
			{
				int a;
				input("",a);
				vec.push_back(a);
			}
			dblVec.push_back(vec);
			vec.clear();
		}
		return dblVec;
	}

	void vecOutput(std::vector<std::vector<int>> vec)
	{
		for (int i = 0; i < vec.size(); i++)
		{
			for (int j = 0; j < vec[i].size(); j++)
			{
				std::cout << vec[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}

	int positiveSum(std::vector<std::vector<int>> vec)
	{
		int sum = 0;
		for (int i = 0; i < vec.size(); i++)
		{
			for (int j = 0; j < vec[i].size(); j++)
			{
				if (vec[i][j] > 0)
					sum += vec[i][j];
			}
		}
		return sum;
	}

	void useSumPos()
	{
		std::vector<std::vector<int>> vec = dblVecInput();
		std::cout << "Your array is:" << std::endl;
		vecOutput(vec);
		std::cout << "Your sum is " << positiveSum(vec) << std::endl;
		system("pause");
	}
};

class DynMass
{
public:
	std::vector<std::vector<int>> dblVecInput()
	{
		std::vector<std::vector<int>> dblVec;
		std::vector<int> vec;
		int rows;
		int cllmns;
		input("Enter amount of rows:", rows);
		input("Enter amount of collumns:", cllmns);
		for (int i = 0; i < rows; i++)
		{
			for (int i = 0; i < cllmns; i++)
			{
				int a;
				std::cin >> a;
				vec.push_back(a);
			}
			dblVec.push_back(vec);
			vec.clear();
		}
		return dblVec;
	}

	void vecOutput(std::vector<std::vector<int>> vec)
	{
		for (int i = 0; i < vec.size(); i++)
		{
			for (int j = 0; j < vec[i].size(); j++)
			{
				std::cout << vec[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}

	std::vector<int> rowsSum(std::vector<std::vector<int>> dblVec)
	{
		std::vector<int> resVec;
		for (int i = 0; i < dblVec.size(); i++)
		{
			int rowSum = 0;
			for (int j = 0; j < dblVec[i].size(); j++)
			{
				rowSum += dblVec[i][j];
			}
			resVec.push_back(rowSum);
		}
		return resVec;
	}

	void useDynMass()
	{
		std::vector<std::vector<int>> dblVec = dblVecInput();
		std::cout << "Your array is:" << std::endl;
		vecOutput(dblVec);
		std::vector<int> vec = rowsSum(dblVec);
		std::cout << "Your rows sum is " << std::endl;
		for (int i = 0; i < vec.size(); i++)
		{
			std::cout << vec[i] << ' ';
		}
		std::cout << std::endl;
		system("pause");
	}
};

class IndTask3
{
public:
	std::vector<std::vector<int>> dblVecInput()
	{
		std::vector<std::vector<int>> dblVec;
		std::vector<int> vec;
		for (int i = 0; i < 4; i++)
		{
			for (int i = 0; i < 4; i++)
			{
				int a;
				input("", a);
				vec.push_back(a);
			}
			dblVec.push_back(vec);
			vec.clear();
		}
		return dblVec;
	}

	void dblVecOutput(std::vector<std::vector<int>> vec)
	{
		for (int i = 0; i < vec.size(); i++)
		{
			for (int j = 0; j < vec[i].size(); j++)
			{
				std::cout << vec[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}

	std::vector<std::vector<int>> changeVector(std::vector<std::vector<int>> vec)
	{
		for (int i = 0; i < vec.size(); i++)
		{
			for (int j = 0; j < vec[i].size(); j++)
			{
				if (vec[i][j] < 0)
					vec[i][j] *= vec[i][j];
			}
		}
		return vec;
	}

	std::vector<double> diagRoot(std::vector<std::vector<int>> dblVec)
	{
		std::vector<double> vec;
		for (int i = 0; i < 4; i++)
		{
			vec.push_back(sqrt(dblVec[i][i]));
		}
		return vec;
	}

	void useIndTask()
	{
		std::vector<std::vector<int>> dblVec = dblVecInput();
		std::cout << "Your initial array is:" << std::endl;
		dblVecOutput(dblVec);
		dblVec = changeVector(dblVec);
		std::cout << "Your changed array is:" << std::endl;
		dblVecOutput(dblVec);
		std::vector<double> vec = diagRoot(dblVec);
		std::cout << "Your array of roots of duagonal elements is:" << std::endl;
		for (int i = 0; i < vec.size(); i++)
		{
			std::cout << vec[i] << ' ';
		}
		std::cout << std::endl;
		system("pause");
	}
};

class UseLab4
{
public:
	void useLab3()
	{
		std::vector<std::string> menu = { "Sum of minimum and maximum", "Descending order", "Sum of positive numbers",
			"Array in free store", "Individual task" };
		switch (Menu::getInstance().menuOrgan(menu))
		{
		case -1://exit
		{
			return;
		}break;
		case 0:	//Sum of minimum and maximum
		{
			MaxMin ex;
			ex.useFunc();
		}break;
		case 1:		//descending order
		{
			Sort ex;
			ex.useSort();
		}break;
		case 2:		//sum of positive number
		{
			SumPos ex;
			ex.useSumPos();
		}break;
		case 3:		//array in free story
		{
			DynMass ex;
			ex.useDynMass();
		}break;
		case 4:		//individual assignment
		{
			IndTask3 ex;
			ex.useIndTask();
		}break;
		}
	}
};