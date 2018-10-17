#pragma once
#undef max
#undef min

template <typename T>

void input(const char * prompt, T& var)
{
	for (;;)
	{
		std::cout << prompt << std::flush;
		if ((std::cin >> var).good()) return;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cout << "Wrong input, try again\n";
		}
		std::cin.ignore(std::numeric_limits<std::size_t>::max(), '\n');
	}
}
