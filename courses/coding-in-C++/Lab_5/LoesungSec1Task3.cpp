#include <iostream>

template <typename T>
T smallest(T var_1, T var_2)
{
	if (var_1 < var_2)
	{
		return var_1;
	}

	return var_2;
}

int main()
{
	int var_1 = 5;
	int var_2 = 1;

	std::cout << smallest(var_1, var_2) << std::endl;

	double var_4 = 7.9;
	double var_5 = 2.5;

	std::cout << smallest(var_4, var_5) << std::endl;

	return 0;
}