#pragma once

class SqVec
{
private:
	static const int size = 4;
	std::vector<std::vector<int>> vec;
public:
	SqVec() {};

	void vecInput()
	{
		std::vector<int> v;
		std::cout << "Enter your Matrix, size is 4x4:" << std::endl;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				int a;
				input("", a);
				v.push_back(a);
			}
			vec.push_back(v);
			v.clear();
		}
	}

	void vecOutput()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				std::cout << vec[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}

	SqVec operator+(const SqVec &t)
	{
		SqVec res = emptyVec();
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				res.vec[i][j] = vec[i][j] + t.vec[i][j];
		return res;
	}

	SqVec operator-(const SqVec &t)
	{
		SqVec res = emptyVec();
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				res.vec[i][j] = vec[i][j] - t.vec[i][j];
		return res;
	}

	SqVec operator*(const SqVec &t)
	{
		SqVec res = emptyVec();
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				res.vec[i][j] = 0;
				for (int k = 0; k < size; k++)
				{
					res.vec[i][j] += (vec[i][k] * t.vec[k][j]);
				}
			}
		}
		return res;
	}


	int getByIndex()
	{
		int r, c;
		while (true)
		{
			input("Enter index of row: ", r);
			if (r > 0 && r <= size)
				break;
			std::cout << "Your 'r' should be 0 <= r <4 " << std::endl;
		}
		while (true)
		{
			input("Enter index of collumn: ", c);
			if (c > 0 && c <= size)
				break;
			std::cout << "Your 'c' should be 0 <= c < 4 " << std::endl;
		}
		return vec[r - 1][c - 1];
	}

	SqVec emptyVec()
	{
		SqVec a;
		for (int i = 0; i < 4; ++i)
		{
			std::vector<int> vec(4);
			a.vec.push_back(vec);
		}
		return a;
	}

	~SqVec() {};
};

void useVec()
{
	SqVec mat1;
	SqVec mat2;
	SqVec res;
	mat1.vecInput();
	mat2.vecInput();
	std::cout << "Your initial arrays are:" << std::endl;
	mat1.vecOutput();
	std::cout << std::endl;
	mat2.vecOutput();
	std::cout << std::endl << "____________________________________________________"
		<< "a + b = " << std::endl;
	res = mat1 + mat2;
	res.vecOutput();
	std::cout << "a - b = " << std::endl;
	res = mat1 - mat2;
	res.vecOutput();
	std::cout << "a * b =" << std::endl;
	res = mat1 * mat2;
	res.vecOutput();
	std::cout << "Let's give element from first matrix by index: " << std::endl;
	int a = mat1.getByIndex();
	std::cout << "This element is " << a << std::endl;
	system("pause");
}

//----------------------------------------------------------------------------

class Stud
{
private:
	unsigned int numb;
	std::string surname;
	std::vector<int> balls;
public:
	Stud() {}

	Stud(unsigned int numb, std::string surname, std::vector<int> balls)
	{
		this->numb = numb;
		this->surname = surname;
		this->balls = balls;
	}

	unsigned int getNumb()
	{
		return numb;
	}

	std::string getSurname()
	{
		return surname;
	}

	std::vector<int> getBalls()
	{
		return balls;
	}

	bool isEven()
	{
		if (numb % 2 == 0)
			return true;
		else
			return false;
	}

	friend bool operator< (Stud &t1, Stud &t2);

	friend std::ostream& operator<< (std::ostream &out, Stud &t);

	friend std::istream& operator>> (std::istream &in, Stud &t);
};

bool operator< (Stud &t1, Stud &t2)
{
	const char* a1 = t1.surname.c_str();
	const char* a2 = t2.surname.c_str();
	int res = strcmp(a1, a2);
	if (res == -1)
		return true;
	else
		return false;
}

std::ostream& operator<< (std::ostream &out, Stud &t)
{
	out << "Number: " << t.numb << std::endl
		<< "Surname: " << t.surname << std::endl
		<< "Balls: ";
	for (int i = 0; i < t.getBalls().size(); i++)
	{
		out << t.balls[i] << " ";
	}
	out << std::endl;
	return out;
}

std::istream& operator>> (std::istream &in, Stud &t)
{
	input("Enter number: ", t.numb);
	std::cout << "Enter surname: ";
	in >> t.surname;
	int am;
	input("Enter amount of balls: ", am);
	std::cout << "Enter your balls: ";
	for (int i = 0; i < am; i++)
	{
		int a;
		input("", a);
		t.balls.push_back(a);
	}
	return in;
}

class Group
{
private:
	std::vector<Stud> memb;
public:
	Group() {};

	void sort()
	{
		std::sort(memb.begin(), memb.end());
	}

	Group justEven()
	{
		Group res;
		for (int i = 0; i < memb.size(); i++)
		{
			if (memb[i].isEven() == true)
				res.memb.push_back(memb[i]);
		}
		return res;
	}

	friend std::ostream& operator<< (std::ostream &out, Group &t);

	friend std::istream& operator>> (std::istream &in, Group &t);
};

std::ostream& operator<< (std::ostream &out, Group &t)
{
	for (int i = 0; i < t.memb.size(); i++)
	{
		out << t.memb[i];
		out << std::endl;
	}
	return out;
}

std::istream& operator>> (std::istream &in, Group &t)
{
	int a;
	input("Enter amount of students in group: ", a);
	for (int i = 0; i < a; i++)
	{
		Stud st;
		in >> st;
		t.memb.push_back(st);
		std::cout << std::endl;
	}
	return in;
}

void useGroup()
{
	Group gr1;

	std::cin >> gr1;

	std::cout << "Entered data:" << std::endl
		<< gr1 << std::endl;

	gr1.sort();

	std::cout << "Sorted group:" << std::endl
		<< gr1 << std::endl;

	Group res = gr1.justEven();

	std::cout << "Just even:" << std::endl
		<< res << std::endl;

	system("pause");
}

//-------------------------------------------------------------------------------

void _2_alg_3()
{
	while (true)
	{
		system("cls");
		std::vector<std::string> parts = { "Vector of vectors",
			"Representation and Data Processing About the Students"};
		switch (Menu::getInstance().menuOrgan(parts))
		{
		case -1:
			return;
			break;
		case 0:
		{
			useVec();
		}break;
		case 1:
		{
			
		}break;
		}
	}
}