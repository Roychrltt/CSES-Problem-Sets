#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int main()
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
		int first = v[i].first, second = v[i].second;
		int min = std::min(first, second), max = std::max(first, second);
		long long int ans;
		if ((first <= second && max % 2 == 1) || (first >= second && max % 2 == 0))
			ans = static_cast<long long>(max) * max - min + 1;
		else
			ans = static_cast<long long>(max) * (max - 2) + min + 1;
		std::cout << ans << std::endl;
	}
	return 0;
}
