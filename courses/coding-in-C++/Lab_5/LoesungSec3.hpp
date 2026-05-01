#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

template <typename T>
T summe(const std::vector<T> &vec)
{
	return std::accumulate(vec.begin(), vec.end(), T());
}

template <typename T>
T max(const std::vector<T> &vec)
{
	return *std::max_element(vec.begin(), vec.end());
}

template <typename T>
double durchschnitt(const std::vector<T> &vec)
{
	T sum = summe(vec);
	return static_cast<double>(sum) / vec.size();
}	

template <typename T>
void print(const std::vector<T> &vec)
{
	std::cout << "Daten: ";

	for (const T& wert : vec)
	{
		std::cout << wert << " ";
	}

	std::cout << std::endl;

	std::cout << "Summe: " << summe(vec) << std::endl;
	std::cout << "Max: " << max(vec) << std::endl;
	std::cout << "Avg.: " << durchschnitt(vec) << std::endl;
}

template <typename T, int N>
std::vector<T> transfer(T (&arr)[N])
{
	std::vector<T> neu;

	for (int i = 0; i < N; i++)
	{
		neu.push_back(arr[i]);
	}

	return neu;
}

template <>
bool summe<bool>(const std::vector<bool> &vec)
{
	int sum = std::count(vec.begin(), vec.end(), true);
	bool status = false; 
	if (sum > (vec.size() / 2.0))
	{
		status = true;
	}
	return status;
}

#endif // !HEADER_HPP