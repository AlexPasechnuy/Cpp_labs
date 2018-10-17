//////////////////////	//////////////////////
//	Alex Pasichnuy	//	//	Personal Task	//
//////////////////////	//////////////////////

#include <iostream>
#include <vector>
#include "Lab1.h"
#include "Lab2.h"
#include "menu.h"


int main()
{
	bool isExit = false;
	while (isExit == false)
	{
		system("cls");
		std::cout << "Select your lab:" << std::endl;
		std::vector<std::string> menu = { "Lab 1", "Lab 2" , "Exit"};
		switch (Menu::getInstance().menuOrgan(menu))
		{
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
			isExit = true;
		}break;
		}
	}
	return 0;
}