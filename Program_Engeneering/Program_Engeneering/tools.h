#pragma once
#undef max
#undef min

template <typename T>

void input(const char * prompt, T& var)
{
	/*std::cout << prompt;*/
	while (!(std::cout << prompt) || !(std::cin >> var) || std::cin.peek() != '\n')
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Input error! Retry input" << std::endl;
	}
}