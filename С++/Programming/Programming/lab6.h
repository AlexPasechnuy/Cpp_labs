#pragma once

#include "menu.h"

typedef double(*FuncType)(double);

double g(double x)
{
	return x * x * x - 2;
}

class Bisection
{
public:
	double root(FuncType f, double a, double b, double eps = 0.001)
	{
		double x;
		do
		{
			x = (a + b) / 2;
			if (f(a) * f(x) > 0)
			{
				a = x;
			}
			else
			{
				b = x;
			}
		} while (fabs(b - a) > eps);
		return x;
	}

	void useBisection()
	{
		std::cout << root(g, 0, 6) << std::endl;
		std::cout << root(g, 0, 6, 0.00001) << std::endl;
		std::cout << root(sin, 1, 4) << std::endl;
		std::cout << root(sin, -1, 4, 0.00001) << std::endl;
		system("pause");
	}
};




class IndTask6
{
public:
	double leastRoot(FuncType f, double a, double b, double step, double eps)
	{
		double root;
		double smallRoot;
		for (double i = a; a <= b; a += step)
		{
			float x0 = a + eps;
			double Numerator = (f(a + eps) - f(x0 + eps)) / ((a + eps) - (x0 + eps))
				- (f(a) - f(x0)) / (a- x0);
			root = Numerator / eps;
			if (i == a)
			{
				smallRoot = root;
			}
			else
			{
				if (root < smallRoot)
				{
					smallRoot = root;
				}
			}
		}
		return smallRoot;
	}

	void useIndTask6()
	{
		std::cout << leastRoot(g, 1, 5, 1, 0.0000001) << std::endl;;
		system("pause");
	}
};

class UseLab6
{
public:
	void useLab6()
	{
		std::vector<std::string> menu = { "Bisection", "Individual task" };
		switch (Menu::getInstance().menuOrgan(menu))
		{
		case -1:	//exit
		{
			return;
		}break;
		case 0:		//Bisection
		{
			Bisection ex;
			ex.useBisection();
		}break;
		case 1:		//Individual Assignment
		{
			IndTask6 ex;
			ex.useIndTask6();
		}break;
		}
	}
};