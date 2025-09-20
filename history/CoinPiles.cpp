#include <iostream>
#include <vector>

int main(void)
{
	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> v;
	v.reserve(n);
	for (int i = 0; i < n; i++)
	{
		int first, second;
		std::cin >> first >> second;
		v.emplace_back(first, second);
	}
	for (int i = 0; i < n; i++)
	{
		int a = v[i].first, b = v[i].second;
		if ((2 * b - a) % 3 == 0 && (2 * a - b) % 3 == 0 && 2 * b >= a && 2 * a >= b)
			std::cout << "YES" << std::endl;
		else
			std::cout << "NO" << std::endl;
	}
	return 0;
}
