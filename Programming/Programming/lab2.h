#include <iostream>
#include <string>
#include <vector>

class Lab2
{
private:
	bool isExit = false;
public:
	void useLab2()
	{
		std::vector<std::string> data = { "Individual task", "Square equation" , "Looping algoritm", "Sum" , "Product" , "Exit"};
		while (isExit == false)
		{
			std::cout << "Select part of work:";
			switch (Menu::getInstance().menuOrgan(data))
			{
			case 0:
			{
				IndTask ex;
				ex.useIndTask();
			}break;
			case 1:
			{
				SquareEquation ex;
				ex.findResult();
			}break;
			case 2:
			{
				Looping ex;
				ex.findAnswer();
			}break;
			case 3:
			{
				Sum ex;

			}break;
			case 4:
			{
				Product ex;

			}exit;
			case 5:
				isExit = true;
				break;
			}
		}
	}
};

class SquareEquation	//maybe done
{
private:
	double a, b, c, d, x1, x2;
public:
	void findResult()
	{
		d = b*b - 4 * a*c;
		if (d < 0)
		{
			std::cout << "No roots, negative D!!!\n";
			return;
		}
		x1 = (-b + sqrt(d))/2*a;
		x2 = (-b - sqrt(d)) / 2 * a;
		std::cout << "x1 = " << x1 << std::endl << "x2 = " << x2 << std::endl;
	} 
};

class Looping			//maybe done
{
private:
	double x, n, k, sum;
public:
	void findAnswer()
	{
		int sum = 0;
		std::cin >> x >> k >> n;
		for (int i = 1; i <= n; i++)
		{
			if ((x + 2 * i) == 0)
			{
				std::cout << "Incorrect input: division by 0\n";
				system("pause");
				return;
			}
			if(i != k)
			sum += 1 / (x + 2 * i);
		}
		std::cout << "Sum = " << sum << std::endl;
	}
};

class Sum
{
private:

public:

};

class Product
{
private:

public:

};

class IndTask
{
private:
	double n;
	double stepSize;
	double x;
	double maxX;
	double sum;
	std::vector<double> results;
	bool isExit = false;
public:
	void getData()
	{
		std::cout << "Select data input way please:\n";
		std::vector<std::string> giveMenu = { "Give from file", "Give from keyboard" };
		switch (Menu::getInstance().menuOrgan(giveMenu))
		{
		case 0:
			getFromFile();
			break;
		case 1:
			std::cout << "n = ";
			std::cin >> n;
			std::cout << "\nstep = ";
			std::cin >> stepSize;
			std::cout << "\nStart and maximum value of your x :";
			std::cin >> x >> maxX;
			break;
		}
		system("cls");
	}

	void useIndTask()
	{
		while (isExit == false)
		{
			getData();		//input
			if (stepSize <= 0 || (maxX - x) <= 0)
			{
				std::cout << "Incorrect input!!!" << std::endl;
				return;
			}
			for (x; x <= maxX; x += stepSize)
			{
				if (x >= 0)
					positiveX();
				else
					negativeX();
				std::cout << "x = " << x << "; sum = " << sum << std::endl;
				results.push_back(sum);
			}
			returnToFile();
			system("cls");
			std::cout << "Do you want to use the program again?\n";
			switch (Menu::getInstance().menuOrgan({ "Yes", "No" }))
			{
			case 0:
				break;
			case 1:
				isExit = true;
				std::cout << "Thanks for using my product)\n"
					<< "With love, Alex Pasechnuy\n";
				break;
			}
		}
	}

	void getFromFile()
	{
		std::ifstream fin;
		fin.open("InputLab2.txt");
		std::vector<std::vector<double>> data;


		std::vector<std::string> strVec;

		int memb;
		while (!fin.eof())
		{
			std::string str;
			std::vector<double> vecDob;

			for (int i = 0; i < 4; i++)
			{
				fin >> memb;
				vecDob.push_back(memb);
				str += std::to_string(memb) + " ";
			}

			strVec.push_back(str);
			data.push_back(vecDob);
		}
		std::cout << "Select your start and maximum value of x ,n and step size:\n";

		int choise = Menu::getInstance().menuOrgan(strVec);
		std::vector<double> vecDob = data[choise];
		x = vecDob[0];	//interval start
		maxX = vecDob[1];	//interval end
		n = vecDob[2];
		stepSize = vecDob[3];

		fin.close();
	}

	void returnToFile()
	{
		std::ofstream fout;
		fout.open("OutputLab2.txt", std::ios_base::app);
		std::cout << std::endl << "Do you want to save your results to file?" << std::endl;
		switch (Menu::getInstance().menuOrgan({ "Yes", "No" }))
		{
		case 0:
			for (int i = 0; i < results.size(); i++)
			{
				fout << results[i] << " ";
			}
			fout << std::endl;
			fout.close();
			break;
		case 1:
			break;
		}
	}

	void positiveX()
	{
		sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += (x - 1) / (i + 1);
		}
	}

	void negativeX()
	{
		sum = 0;
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				sum += x - (i*i) + j;
			}
		}
	}
};