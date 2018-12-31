//////////////////////	//////////////
//	Alex Pasichnuy	//	//	Labs	//
//////////////////////	//////////////

#include <iostream>
#include <vector>

#include "menu.h"
#include "tools.h"
#include "lab1.h"
#include "lab2.h"
#include "lab3.h"
#include "lab4.h"
#include "lab5.h"
#include "lab6.h"

void firstSem();
void secondSem();
void secProg();
void secAlg();

void firstSem()
{
	while (true)
	{
		system("cls");
		std::cout << "Select your lab:" << std::endl;
		std::vector<std::string> labs = { "Lab 1", "Lab 2", "Lab 3",
			"Lab 4", "Lab 5", "Lab 6" };
		switch (Menu::getInstance().menuOrgan(labs))
		{
		case -1:
			return;
		case 0:
		{
			Lab1 find;
			find.useLab1();
		}break;
		case 1:
		{
			Lab2 find;
			find.useLab2();
		}break;
		case 2:
		{
			Lab3 find;
			find.useLab3();
		}break;
		case 3:
		{
			UseLab4 find;
			find.useLab3();
		}break;
		case 4:
		{
			UseLab5 find;
			find.useLab5();
		}break;
		case 5:
		{
			UseLab6 find;
			find.useLab6();
		}
		}
	}
}

void secondSem()
{
	while (true)
	{
		system("cls");
		std::cout << "Select your subject:" << std::endl;
		std::vector<std::string> subj = { "Algorithmization", "Programming" };
		switch (Menu::getInstance().menuOrgan(subj))
		{
		case -1:
			return;
			break;
		case 0:
		{
			secAlg();
		}break;
		case 1:
		{
			secProg();
		}break;
		}
	}
}

void secProg()
{
	while (true)
	{
		system("cls");
		std::cout << "Select your lab:" << std::endl;
		std::vector<std::string> labs = { "Lab 1", "Lab 2", "Lab 3" };
		switch (Menu::getInstance().menuOrgan(labs))
		{
		case -1:
			return;
			break;
		case 0:
		{
			
		}break;
		case 1:
		{
			
		}break;
		case 2:
		{

		}break;
		}
	}
}

void secAlg()
{
	while (true)
	{
		system("cls");
		std::cout << "Select your lab:" << std::endl;
		std::vector<std::string> labs = { "Lab 1", "Lab 2", "Lab 3" };
		switch (Menu::getInstance().menuOrgan(labs))
		{
		case -1:
			return;
			break;
		case 0:
		{

		}break;
		case 1:
		{

		}break;
		case 2:
		{

		}break;
		}
	}
}

int main()
{
	bool isExit = false;
	while (isExit == false)
	{
		system("cls");
		std::cout << "Select your semester:" << std::endl;
		std::vector<std::string> semesters = { "First", "Second"};
		switch (Menu::getInstance().menuOrgan(semesters))
		{
		case -1:		//exit
			system("cls");
			std::cout << "Thanks for using my product)\n"
					<< "With love, Alex Pasechnuy\n";
			system("pause");
			return 0;
			break;
		case 0:	
			firstSem();
		break;
		case 1:
			secondSem();
		break;
		}
	}
}