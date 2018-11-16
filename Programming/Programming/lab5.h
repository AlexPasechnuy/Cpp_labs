#pragma once

#include <iostream>
#include <cmath>
#include <fstream>

class FindDist
{
public:
	struct Point
	{
		int x, y, z;
	};

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
	std::vector<double> readVac(std::string filename)
	{
		std::vector<double> vec;
		std::ifstream fin;
		fin.open(filename);
		return vec;
	}
};