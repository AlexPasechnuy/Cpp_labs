#pragma once

#include "tools.h"

class Fract
{
private:
	int sign;
	int num;
	int denom;
public:
	Fract() {};

	Fract(int num, int denom)
	{
		this->num = num;
		this->denom = denom;
	}

	void fractInput()
	{
		while (true)
		{
			input("Enter numerator: ", num);
			input("Enter denominator: ", denom);
			if (denom != 0)
			{
				break;
			}
			std::cout << "Your fraction is false, "
				<< "denominator cannot be equal 0!!!" << std::endl
				<< "Let's try again!";
			system("pause");
			system("cls");
		}
	}

	void fractOutput()
	{
		std::cout << num << "/" << denom ;
	}

	void abbrev()
	{
		if (num*denom < 0)
			sign = -1;
		else
			sign = 1;
		num = abs(num);
		denom = abs(denom);
		int least;	//gets least from numerator and denominator
		if (num < denom)
			least = num;
		else
			least = denom;
		for (int i = least; i > 0; i--)
		{		//we cannot divide fraction by number which greater than 'least'
			if (num % i == 0 && denom % i == 0)
			{		//find biggest value by which we can divide fraction
				denom /= i;
				num /= i;
				i = 0;
			}
		}
		num *= sign;
		return;
	}

	Fract operator+(const Fract &t)
	{
		Fract res;
		//multiplying denominators by each other is simliest common denominator
		res.num = t.denom*num + denom * t.num;
		res.denom = denom * t.denom;
		res.abbrev();	//abbreviation of fraction
		return res;
	}

	Fract operator-(const Fract &t)
	{
		Fract res;
		res.num = t.denom*num - denom * t.num;
		res.denom = denom * t.denom;
		res.abbrev();
		return res;
	}

	Fract operator*(const Fract &t)
	{
		Fract res;
		res.num = num * t.num;
		res.denom = denom * t.denom;
		res.abbrev();
		return res;
	}

	Fract operator/(const Fract &t)
	{
		Fract res;
		res.num = num * t.denom;
		res.denom = denom * t.num;
		res.abbrev();
		return res;
	}

	friend bool operator< (const Fract &t1, const Fract &t2);

	~Fract() {};
};

bool operator< (const Fract &t1, const Fract &t2)
{
	double a, b;
	a = double(t1.num) / t1.denom;
	b = double(t2.num) / t2.denom;
	return a < b;
}

void useFract()
{
	Fract num1;
	Fract num2;
	Fract num3;
	num1.fractInput();
	num2.fractInput();
	num3 = num1 + num2;
	std::cout << "a + b" << std::endl;
	num3.fractOutput();
	std::cout << std::endl;
	num3 = num1 - num2;
	std::cout << "a - b" << std::endl;
	num3.fractOutput();
	std::cout << std::endl;
	num3 = num1 * num2;
	std::cout << "a * b" << std::endl;
	num3.fractOutput();
	std::cout << std::endl;
	num3 = num1 / num2;
	std::cout << "a / b" << std::endl;
	num3.fractOutput();
	std::cout << std::endl << "a < b -> " << (num1 < num2) << std::endl;
	system("pause");
}

//--------------------------------------------------------------------------------------

class SqMatrix
{
private:
	static const int size = 4;
	int matr[size][size];
public:
	SqMatrix() {};

	void matrInput()
	{
		std::cout << "Enter your Matrix, size is 4x4:" << std::endl;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				input("", matr[i][j]);
			}
		}
	}

	void matrOutput()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				std::cout << matr[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}

	SqMatrix operator+(const SqMatrix &t)
	{
		SqMatrix res;
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				res.matr[i][j] = matr[i][j] + t.matr[i][j];
		return res;
	}

	SqMatrix operator-(const SqMatrix &t)
	{
		SqMatrix res;
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				res.matr[i][j] = matr[i][j] - t.matr[i][j];
		return res;
	}

	SqMatrix operator*(const SqMatrix &t)
	{
		SqMatrix res;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				res.matr[i][j] = 0;
				for (int k = 0; k < size; k++)
				{
					res.matr[i][j] += (matr[i][k] * t.matr[k][j]);
				}
			}
		}
		return res;
	} 


	int getByIndex()
	{
		int r, c;
		while (true)
		{
			input("Enter index of row: ", r);
			if (r > 0 && r <= size)
				break;
			std::cout << "Your 'r' should be 0 <= r <4 " << std::endl;
		}
		while (true)
		{
			input("Enter index of collumn: ", c);
			if (c > 0 && c <= size)
				break;
			std::cout << "Your 'c' should be 0 <= c < 4 " << std::endl;
		}
		return matr[r - 1][c - 1];
	}

	~SqMatrix() {};
};

void useMatr()
{
	SqMatrix mat1;
	SqMatrix mat2;
	SqMatrix res;
	mat1.matrInput();
	mat2.matrInput();
	std::cout << "Your initial arrays are:" << std::endl;
	mat1.matrOutput();
	std::cout << std::endl;
	mat2.matrOutput();
	std::cout << std::endl << "____________________________________________________"
		<< "a + b = " << std::endl;
	res = mat1 + mat2;
	res.matrOutput();
	std::cout << "a - b = " << std::endl;
	res = mat1 - mat2;
	res.matrOutput();
	std::cout << "a * b =" << std::endl;
	res = mat1 * mat2;
	res.matrOutput();
	std::cout << "Let's give element from first matrix by index: " << std::endl;
	int a = mat1.getByIndex();
	std::cout << "This element is " << a << std::endl;
	system("pause");
}

//--------------------------------------------------------------------------------------

class EntSum
{
private:
	static int sum;
	int num;
public:
	EntSum(int a)
	{
		num = a;
		sum += num;
	}

	static int getSum()
	{
		return sum;
	}
};

int EntSum::sum = 0;

void useSum()
{
	EntSum sum1(2);
	EntSum sum2(3);
	EntSum sum3(4);
	std::cout << sum3.getSum() << std::endl;
	system("pause");
}

//--------------------------------------------------------------------------------------

void _2_alg_1()
{
	while (true)
	{
		system("cls");
		std::vector<std::string> parts = { "Simple fractions", "Two-dimensional array" ,
											"Sum of entered values" };
		switch (Menu::getInstance().menuOrgan(parts))
		{
		case -1:
			return;
			break;
		case 0:
		{
			useFract();
		}break;
		case 1:
		{
			useMatr();
		}break;
		case 2:
		{
			useSum();
		}break;
		}
	}
}