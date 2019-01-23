#include <iostream>
#include <math.h>
#include <vector>

void checkInp()
{
	if (std::cin.fail())
	{
		throw "Incorrect input";
	}
}

void checkParam(int x, int n, int xMax, int step)
{
	if (xMax < x)
		throw "!Your interval has negative direction!";
	if (step <= 0)
		throw "!Incorrect step size!";
	if (n < 2)
		throw "!Your n is too small for this x!";
}

int positiveX(int x, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += (x - 1) / (i + 1);
	}
	return sum;
}

int negativeX(int x, int n)
{
	int sum = 0;
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			sum += x - (i*i) + j;
		}
	}
	return sum;
}

int calc(int x, int n)
{
		int sum;
		if (x >= 0)
			sum = positiveX(x, n);
		else
			sum = negativeX(x, n);
		return sum;
}

void calculations(int x, int n, int xMax, int step)
{
	for (x; x <= xMax; x += step)
	{
		int a = calc(x, n);
		std::cout << "x = " << x << "; n = " << n << std::endl;
	}
}

int main()
{
	int x, n, xMax, step;
	try
	{
		std::cout << "Input x = ";
		std::cin >> x;
		checkInp();

		std::cout << "Input n > 2, n = ";
		std::cin >> n;
		checkInp();

		std::cout << "Input xMax = ";
		std::cin >> xMax;
		checkInp();

		std::cout << "Input step = ";
		std::cin >> step;
		checkInp();

		checkParam(x, n, xMax, step);
		calculations(x, n, xMax, step);
		//std::cout << "x = " << x << "; y = " << calc(x, n) << std::endl;
		system("pause");
	}
	catch (const char* ex)
	{
		std::cout << ex << std::endl;
		system("pause");
		return -1;
	}
	catch (...)
	{
		std::cout << "Unknown error" << std::endl;
		system("pause");
		return -2;
	}
}