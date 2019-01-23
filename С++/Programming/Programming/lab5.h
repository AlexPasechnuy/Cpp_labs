#pragma once

#include "tools.h"

class FindDist
{
private:
	struct Point
	{
		int x, y, z;
	};
public:
	double sqr(double x)
	{
		return x * x;
	}

	double distance(Point p1, Point p2)
	{
		return std::sqrt(sqr(p1.x - p2.x) + sqr(p1.y - p2.y)+ sqr(p1.z - p2.z));
	}

	void useFindDist()
	{
		Point p1 = { 1, 2 , 3};
		Point p2 = { 4, 6 };
		printf("%f", distance(p1, p2));
		system("pause");
	}
};

class Average
{
public:
	std::vector<double> readVec(std::string filename)
	{
		std::vector<double> vec;
		std::ifstream fin;
		fin.open(filename);
		if (!fin.is_open())
			std::cout << "Cannot open the file" << std::endl;
		else
		{
			while (!fin.eof())
			{
				double a;
				fin >> a;
				vec.push_back(a);
			}
		}
		fin.close();
		return vec;
	}

	void printVec(std::vector<double> vec)
	{
		for (int i = 0; i < vec.size(); i++)
		{
			std::cout << vec[i] << ' ';
		}
		std::cout << std::endl;
	}

	double findAv(std::vector<double> vec)
	{
		double sum = 0;
		for (int i = 0; i < vec.size(); i++)
		{
			sum += vec[i];
		}
		double av = sum / vec.size();
		return av;
	}

	void useAv()
	{
		std::vector<double> vec = readVec("file.txt");
		std::cout << "Your array is" << std::endl;
		printVec(vec);
		std::cout << "Arithmetic mean of these values is "
			<< findAv(vec) << "." << std::endl;
		system("pause");
	}
};

class IndTask5
{
private:
	struct Link
	{
		double data;
		Link *next;
	};
	const int amount = 4;
public:
	inline int* readFromFile(std::string fileName, int &count)
	{
		Link *first = 0;
		Link *last = 0;
		Link *link;
		std::ifstream in(fileName);
		count = 0;
		while (!in.eof())		///////////////////////////////////////
		{
			int d;
			in >> d;
			count++;
			link = new Link;
			link->data = d;
			link->next = 0;
			if (last == 0)
			{
				first = last = link;
			}
			else
			{
				last->next = link;
			}
			last = link;
		}
		int *arr = new int[count];
		link = first;
		for (int i = 0; i < count; i++)
		{
			arr[i] = link->data;
			link = link->next;
		}
		while (first)
		{
			link = first;
			first = first->next;
			delete link;
		}
		return arr;
	}

	void printVec(int **arr, int n)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				std::cout << arr[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}

	void outToFile(std::string filename, double *arr, int count)
	{
		std::ofstream out(filename);
		for (int i = count - 1; i >= 0; i--)
		{
			out << arr[i] << " ";
		}
	}

	void useIndTask5()
	{
		int temp;
		const int n = 4;
		int count = 0;
		int *arr = readFromFile("test.txt", count);
		int **a = new int*[n]; // massive with dynamic number of lines filled with massive arr anf 0
		for (int i = 0; i < n; i++)
		{
			a[i] = new int[n];
		}
		int k = 0;

		for (int i = 0; i < n; i++) //filling
		{
			for (int j = 0; j < n; j++)
			{
				if (k < count)
				{
					a[i][j] = arr[k];
					k++;
				}
				else a[i][j] = 0;
			}
		}

		std::cout << "Start array is:" << std::endl;
		printVec(a, n);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (a[i][j] < 0)
					a[i][j] *= a[i][j];
			}
		}

		double *outArr = new double[n];

		for (int i = 0; i < n; i++)
		{
			outArr[i] = sqrt(a[i][i]);
		}

		std::cout << std::endl << "Your changed array is:" << std::endl;
		printVec(a, n);

		std::cout << std::endl << "Your result array is:" << std::endl;
		for (int i = 0; i < n; i++)
		{
			std::cout << outArr[i] << ' ';
		}
		std::cout << std::endl;
		outToFile("results.txt", outArr, count);

		for (int i = 0; i < n; i++)
		{
			delete[] a[i];
		}
		delete[] a;
		delete[] arr;
		system("pause");
	}
};

class UseLab5
{
public:
	void useLab5()
	{
		std::vector<std::string> menu = { "Distance between two points", "Average value", "Individual task"};
		switch (Menu::getInstance().menuOrgan(menu))
		{
		case -1:	//exit
		{
			return;
		}break;
		case 0:		//3D-points
		{
			FindDist ex;
			ex.useFindDist();
		}break;
		case 1:		//Average
		{
			Average ex;
			ex.useAv();
		}break;
		case 2:		//Individual Assignment
		{
			IndTask5 ex;
			ex.useIndTask5();
		}break;
		}
	}
};