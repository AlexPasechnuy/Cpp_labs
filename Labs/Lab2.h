#include <iostream>
#include "Lab1.h"

class Lab2
{
private:
	double x;
	double n;
	double sum;
public:
	void useLab2();
	void getFromFile();
	void moveToFile();
};

void useLab2()
{

}

void Lab2::getFromFile()
{
	std::ifstream fin;
	fin.open("Input.txt");
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

void Lab2::moveToFile()
{
	std::ofstream fout;
	fout.open("Output.txt", std::ios_base::app);
	fout << sum << std::endl;
	fout.close();

}