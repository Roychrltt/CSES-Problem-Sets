#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>



int main()
{
	int n;
	std::cin >> n;
	for (long long int i = 1; i < n + 1; i++)
	{
		long long total = (i * i) * (i * i - 1) / 2;
		long long invalid = i > 2 ? 4 * (i - 1) * (i - 2) : 0;
		std::cout << total - invalid << std::endl;
	}
	return 0;
}
