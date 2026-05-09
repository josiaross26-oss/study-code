#include <iostream>

template <typename T, typename U>
void print(const T& value_1, const U& value_2, const std::string& string_1, const std::string& string_2)
{
	std::cout << string_1 << ": " << value_1 << " | " << string_2 << ": " << value_2;
}

int main()
{
	std::string value_1 = "motor_temp";
	std::string string_1 = "Channel";
	std::string string_2 = "Priority";
	int value_2 = 2;

	print(value_1, value_2, string_1, string_2);

	return 0;
}