//////////////////////	//////////////////////
//	Alex Pasichnuy	//	//	Personal Task	//
//////////////////////	//////////////////////

//сделать большой цикл для нескольких вычислений, не выходя из приложения
//доделать файловый ввод/вывод
//желательно не выпускать курсор за границы меню

#include <iostream>
#include <vector>
#include "Lab1.h"
#include "Lab2.h"
#include "menu.h"

int main()
{
	std::cout << "Select your lab:" << std::endl;
	std::vector<std::string> menu = { "Lab 1", "Lab 2" };
	switch (Menu::getInstance().menuOrgan(menu))
	{
	case 0:
	{
		Lab1 find;
		find.useLab1();
	}
	case 1:
	{
		Lab2 find;
		find.useLab2();
	}
	}
	
	system("pause");
	return 0;
}