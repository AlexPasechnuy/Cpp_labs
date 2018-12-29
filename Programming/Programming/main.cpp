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

int main()
{
	while (true)
	{
		system("cls");
		std::cout << "Select your lab:" << std::endl;
		std::vector<std::string> menu = { "Lab 1", "Lab 2", "Lab 3",
			"Lab 4", "Lab 5", "Lab 6"};
		switch (Menu::getInstance().menuOrgan(menu))
		{
		case -1:
			system("cls");
			std::cout << "Thanks for using my product)\n"
				<< "With love, Alex Pasechnuy\n";
			system("pause");
			return 0;
			break;
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
		}
		case 3:
		{
			UseLab4 find;
			find.useLab3();
		}
		case 4:
		{
			UseLab5 find;
			find.useLab5();
		}
		case 5:
		{
			UseLab6 find;
			find.useLab6();
		}
		}
	}
}