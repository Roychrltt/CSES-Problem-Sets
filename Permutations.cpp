#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int main()
{
	int n;
	std::cin >> n;

	if (n == 1) 
	{
		std::cout << "1" << std::endl;
		return 0;
	}
	else if (n < 4) 
	{
		std::cout << "NO SOLUTION" << std::endl;
		return 0;
	}

	int first = 2;
	int second = 1;
	while (first <= n)
	{
		std::cout << first << " ";
		first += 2;
	}
	while (second <= n)
	{
		std::cout << second;
		if (second < n - 1) std::cout << " ";
		second += 2;
	}
	std::cout << std::endl;
	return 0;
}
