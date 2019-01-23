#pragma once

class Human
{
private:
	std::string name;
	std::string surname;
	int age;
	int height;
	int weight;
	std::string gender;
public:
	Human(std::string name, std::string surname, int age, int height, int weight, std::string gender)
	{
		this->name = name;
		this->surname = surname;
		this->age = age;
		this->height = height;
		this->weight = weight;
		this->gender = gender;
	}

	virtual void show()
	{
		std::cout << "Name: " << name << std::endl;
		std::cout << "Surname: " << surname << std::endl;
		std::cout << "Age: " << age << std::endl;
		std::cout << "Height: " << height << std::endl;
		std::cout << "Weight: " << weight << std::endl;
		std::cout << "Gender: " << gender << std::endl;
	}
};

class Citizen : public Human
{
private:
	std::string country;
	std::string status;
public:
	Citizen(std::string name, std::string surname, int age, int height,
		int weight, std::string gender, std::string country, std::string status)
		: Human(name, surname, age, height, weight, gender)
	{
		this->country = country;
		this->status = status;
	}

	void show() override
	{
		Human::show();
		std::cout << "Country of residence: " << country << std::endl;
		std::cout << "Status: " << status << std::endl;
	}
};

class Student : public Citizen
{
private:
	std::string univer;
	int course;
	std::string group;
	double avBall;
public:
	Student(std::string name, std::string surname, int age, int height,
		int weight, std::string gender, std::string country,
		std::string univer, int course, std::string group, int avBall)
		: Citizen(name, surname, age, height, weight, gender, country, "Student")
	{
		this->univer = univer;
		this->course = course;
		this->group = group;
		this->avBall = avBall;
	}

	void show() override
	{
		Citizen::show();
		std::cout << "University: " << univer << std::endl;
		std::cout << "Course: " << course << std::endl;
		std::cout << "Group: " << group << std::endl;
		std::cout << "Average ball: " << avBall << std::endl;
	}
};

class Employee : public Citizen
{
private:
	std::string company;
	int exp;
	std::string position;
	int salary;
public:
	Employee(std::string name, std::string surname, int age, int height,
		int weight, std::string gender, std::string country,
		std::string company, int exp, std::string position, int salary)
		: Citizen(name, surname, age, height, weight, gender, country, "Employee")
	{
		this->company = company;
		this->exp = exp;
		this->position = position;
		this->salary = salary;
	}

	void show() override
	{
		Citizen::show();
		std::cout << "Company: " << company << std::endl;
		std::cout << "Experience: " << exp << " years" << std::endl;
		std::cout << "Position: " << position << std::endl;
		std::cout << "Salary: " << salary << " USD" << std::endl;
	}
};

void useHierarchy()
{
	Human john("John", "Price", 56, 175, 67, "Male");
	Citizen olga("Olga", "Pupkina", 43, 162, 50, "Female", "Ukraine", "Housework");
	Student viktor("Ivan", "Tikhonov", 17, 175, 65, "Male", "Russia", "HNURE",
		1, "g8.102NK.1", 92);
	Employee anna("Anna", "Ivanova", 27, 175, 75, "Male", "Ukraine", "Jabil",
		3, "Middle C++ Developer", 2500);
	Human* poi[4];
	poi[0] = &john;
	poi[1] = &olga;
	poi[2] = &viktor;
	poi[3] = &anna;
	for (int i = 0; i < 4; i++)
	{
		poi[i]->show();
		std::cout << std::endl;
	}
	system("pause");
}

//----------------------------------------------------------------------------------

class Poli
{
private:

public:
	double leastRoot(FuncType f, double a, double b, double step, double eps)
	{
		double root;
		double smallRoot;
		for (double i = a; a <= b; a += step)
		{
			float x0 = a + eps;
			double Numerator = (f(a + eps) - f(x0 + eps)) / ((a + eps) - (x0 + eps))
				- (f(a) - f(x0)) / (a - x0);
			root = Numerator / eps;
			if (i == a)
			{
				smallRoot = root;
			}
			else
			{
				if (root < smallRoot)
				{
					smallRoot = root;
				}
			}
		}
		return smallRoot;
	}

	virtual double g(double x)
	{
		return x * x * x - 2;
	}
};

void usePoly()
{
	Poli a;
	std::cout << a.leastRoot(g, 1, 5, 1, 0.0000001) << std::endl;
	std::cout << a.leastRoot(sin, -1, 2, 1, 0.0000001) << std::endl;
	system("pause");
}

//-------------------------------------------------------------------------------------

template <typename T> class TempEntSum
{
private:
	static T sum;
	T num;
public:
	TempEntSum(T a)
	{
		num = a;
		sum += num;
	}

	static T getSum()
	{
		return sum;
	}
};

int TempEntSum<int>::sum = 0;
double TempEntSum<double>::sum = 0;

void useTemplates()
{
	std::cout << "Sum of integers: ";
	TempEntSum<int> sum1(2);
	TempEntSum<int> sum2(3);
	TempEntSum<int> sum3(4);
	std::cout << sum3.getSum() << std::endl
		<< "Sum of 'double' numbers: ";

	TempEntSum<double> sum4(0.2);
	TempEntSum<double> sum5(0.5);
	TempEntSum<double> sum6(0.3);
	std::cout << sum6.getSum() << std::endl;
}

//----------------------------------

template<class T>

T findMin(T arr[4][4])
{
	T min = arr[0][0];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (arr[i][j] < min)
				min = arr[i][j];
		}
	}
	return min;
}

void useFindMin()
{
	Fract frct[4][4] = { {Fract(1,4),Fract(-2,5),Fract(6,8),Fract(5,9) },
	{Fract(9,3),Fract(3,9),Fract(-5,-8),Fract(4,9) },
	{Fract(4,4),Fract(6,4),Fract(9,25),Fract(18,4) },
	{Fract(1,42),Fract(10,4),Fract(1,34),Fract(1,14) }};

	int intgr[4][4] = { {1, 3, -2, 9},
	{-5, 8, 12, -9},
	{-20, 17, -14, -17},
	{-40, 50, 14, 34} };

	double dbl[4][4] = { {1.6, 3.9, -2.7, 9.56},
	{-5.9, 8.4, 12.6, -9.3},
	{-20.9, 17.1, -14.8, -17.3},
	{-40.58, 50.63, 14.4, 34.2} };

	std::cout << std::endl << "Your arrays: " << std::endl << std::endl;

	std::cout << "Simple fractions: " << std::endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			frct[i][j].abbrev();
			frct[i][j].fractOutput();
			std::cout << ' ';
		}
		std::cout << std::endl;
	}

	std::cout << "Integers: " << std::endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << intgr[i][j] << ' ';
		}
		std::cout << std::endl;
	}

	std::cout << "'Double' numbers: " << std::endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << dbl[i][j] << ' ';
		}
		std::cout << std::endl;
	}

	std::cout << "Minimum values of arrays: " << std::endl;
	std::cout << "Simple fractions: ";
	findMin(frct).fractOutput();
	std::cout << std::endl
		<< "Integers: " << findMin(intgr) << std::endl
		<< "'Double' numbers: " << findMin(dbl) << std::endl;
}

void useTempArr()
{
	useTemplates();
	useFindMin();
	system("pause");
}

//-----------------------------------------------------------------------------------

void _2_alg_2()
{
	while (true)
	{
		system("cls");
		std::vector<std::string> parts = { "The hierarchy of classes", 
			"Using Polymorphism", "Class Template for Representation of Two-Dimensional Array"};
		switch (Menu::getInstance().menuOrgan(parts))
		{
		case -1:
			return;
			break;
		case 0:
		{
			useHierarchy();
		}break;
		case 1:
		{
			usePoly();
		}break;
		case 2:
		{
			useTempArr();
		}break;
		}
	}
}