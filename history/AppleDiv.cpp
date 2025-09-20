#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> v[i];
	}
	std::sort(v.begin(), v.end());
	long long sum = 0;
	for (int num : v)
		sum += num;
	std::function<long long(int, long long int)> dfs = [&](int i, long long int cur) -> long long
	{
		if (i == n) return std::abs(sum - cur * 2);

		long long cur1 = dfs(i + 1, cur + v[i]);
		long long cur2 = dfs(i + 1, cur);

		return std::min(cur1, cur2);
	};
	std::cout << dfs(0, 0) << std::endl;
	return 0;
}
