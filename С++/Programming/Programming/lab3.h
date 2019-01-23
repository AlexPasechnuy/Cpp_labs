#pragma once

#include "tools.h"

class IndTask2
{
private:
	double x;
	double n;
	double sum;
	bool isExit = false;
public:
	void useIndTask()
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

	void getData()
	{
		std::cout << "Select data input way please:\n";
		std::vector<std::string> giveMenu = { "Give from file", "Give from keyboard" };
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

	void getFromFile()
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

	void returnToFile()
	{
		std::ofstream fout;
		fout.open("OutputLab1.txt", std::ios_base::app);
		fout << sum << std::endl;
		fout.close();

	}

	void positiveX()
	{
		sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += (x - 1) / (i + 1);
		}
	}

	void negativeX()
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

	void show()
	{
		std::vector<std::string> is = { "Yes", "No" };
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
};

class DefArg
{
public:
	void useDefArg()
	{
		int a, b, c;
		c = 0;
		std::cout << "Press 'esc' if you don't want to input 'a' and another key to input" << std::endl;
		int ch = _getch();
		if (ch != 27)
		{
			input("Enter your 'a': ", a);
			c++;
			std::cout << "Press 'esc' if you don't want to input 'b' and another key to input" << std::endl;
			int chh = _getch();
			if (chh != 27)
			{
				input("Enter your 'b': ", b);
				c++;
			}
		}
		if (c == 0)
			std::cout << defArgum() << std::endl;
		else if (c == 1)
			std::cout << defArgum(a) << std::endl;
		else if (c == 2)
			std::cout << defArgum(a, b) << std::endl;
		system("pause");
	}
	double defArgum(int a = 1, int b = 1)
	{
		return a*b;
	}
};

class Lab3
{
private:

public:
	void useLab3()
	{
		std::vector<std::string> menu = { "Static local variables", "Recursion", "Default arguments", "Square equation", "Individual task" };
		switch (Menu::getInstance().menuOrgan(menu))
		{
		case -1:	//exit
		{
			return;
		}break;
		case 0:		//static local variables
		{
			statLocVar();
		}break;
		case 1:		//recursion
		{
			int x;
			double n;
			input("Input x: ", x);
			input("Input n: ", n);
			std::cout << recurs(x, n) << std::endl;
			system("pause");
		}break;
		case 2:		//deault arguents
		{
			DefArg obj;
			obj.useDefArg();
		}break;
		case 3:		//square equation
		{
			double a, b, c, x1, x2;
			while (true)
			{
				input("Enter a: ", a);
				input("Enter b: ", b);
				input("Enter c: ", c);
				if (squareEq(a, b, c, x1, x2) == true)
				{
					std::cout << "Your x1 is " << x1 << " and x2 is " << x2 << std::endl;
					system("pause");
					break;
				}
				std::cout << "Negative discriminant!!!" << std::endl;
				system("pause");
			}
		}break;
		case 4:		//individual task
		{
			IndTask2 ind;
			ind.useIndTask();
		}break;
		}
	}

	bool squareEq(double a, double b, double c, double& x1, double& x2)
	{
		int discr = (b*b) - (4 * a * c);
		if (discr < 0)
			return false;
		x1 = (-b + sqrt(discr)) / (2 * a);
		x2 = (-b - sqrt(discr)) / (2 * a);
		return true;
	}

	void statLocVar()
	{
		int a;
		static int min, max;
		input("Enter new number:", a);
		max = min = a;
		std::cout << "Minium is " << min << " and maximum is " << max << std::endl;
		while (true)
		{
			input("Enter new number:", a);
			if (a < min)
				min = a;
			if (a > max)
				max = a;
			std::cout << "Minium is " << min << " and maximum is " << max
				<< "\nTap 'esc' to exit, or another key to continue!" << std::endl;
			int ch = _getch();
			if (ch == 27)
				break;
		}
	}

	double recurs(double x, int n)
	{
		if (n <= 1)
		{
			return x + n;
		}
		else
		{
			return (x + n) * recurs(x, n - 1);
		}
	}
};