#include <iostream>

int main()
{
	long long int n;
	std::cin >> n;
	int count = 0;
	while (n >= 1)
	{
		if (count++ > 0)
			std::cout << " ";
		std::cout << n;
		if (n == 1) break;
		if (n % 2 == 0) n /= 2;
		else n = n * 3 + 1;
	}
	std::cout << std::endl;
	return 0;
}
