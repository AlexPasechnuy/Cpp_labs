//////////////////////	//////////////////////
//	Alex Pasichnuy	//	//	Personal Task	//
//////////////////////	//////////////////////

//сделать большой цикл для нескольких вычислений, не выходя из приложения
//доделать файловый ввод/вывод
#include <iostream>
#include <vector>
#include "Lab1.h"
#include "Lab2.h"
#include "menu.h"

int main()
{
	while (true)
	{
		system("cls");
		std::cout << "Select your lab:" << std::endl;
		std::vector<std::string> menu = { "Lab 1", "Lab 2", "Exit"};
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
			std::cout << "Thanks for using my product)\n"
				<< "With love, Alex Pasechnuy\n";
			system("pause");
			return 0;
			break;
		}
	}
}