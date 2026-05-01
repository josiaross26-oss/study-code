#include "header.hpp"
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vector = { 9,6,4,2,9,5 };
	print(vector);

	std::cout << std::endl << std::endl;

	std::vector<double> vector_2 = { 1.5 ,2.8 ,3.2 ,4.9 ,5.7 ,6.5 };
	print(vector_2);

	std::cout << std::endl << std::endl;

	int arr[7] = { 1, 2, 3, 4, 5, 6, 7 };
	std::vector<int> vector_3 = transfer(arr);
	print(vector_3);

	std::cout << std::endl << std::endl;

	std::vector<bool> motorStatus = { true, true, true, false, false, true };
	bool avg = summe(motorStatus);
	std::cout << "Motor was acitve for most of the test run: " << std::boolalpha << avg << std::endl;

	return 0;
}