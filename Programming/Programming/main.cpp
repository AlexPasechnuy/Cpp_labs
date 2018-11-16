//////////////////////	//////////////
//	Alex Pasichnuy	//	//	Labs	//
//////////////////////	//////////////

//сделать большой цикл для нескольких вычислений, не выходя из приложения
//доделать файловый ввод/вывод
#include <iostream>
#include <vector>
#include "Lab1.h"
#include "Lab2.h"
#include "Lab3.h"
#include "Lab4.h"
#include "menu.h"
#include "Lab5.h"

int main()
{
	while (true)
	{
		system("cls");
		std::cout << "Select your lab:" << std::endl;
		std::vector<std::string> menu = { "Lab 1", "Lab 2", "Lab 3", "Lab 4"};
		switch (Menu::getInstance().menuOrgan(menu))
		{
		case -1:
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
			
		}
		}
	}
}