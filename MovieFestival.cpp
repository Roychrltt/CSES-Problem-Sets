#include <bits/stdc++.h>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> v(n, std::vector<int>(2));
	for (int i = 0; i < n; i++) {
		std::cin >> v[i][0] >> v[i][1];
	}
	std::sort(v.begin(), v.end(), [](auto& a, auto& b)
		{ return a[1] < b[1];});
	int ans = 0;
	int endTime = 0;
	for (auto& a : v)
	{
		if (a[0] >= endTime)
		{
			ans++;
			endTime = a[1];
		}
	}
	std::cout << ans << std::endl;
	return 0;
}
