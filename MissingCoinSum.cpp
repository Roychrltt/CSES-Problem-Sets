#include <bits/stdc++.h>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n;
	std::cin >> n;
	std::vector<long long> v(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> v[i];
	}
	std::sort(v.begin(), v.end());
	long long int count = 1;
	for (int i = 0; i < n; i++) {
		if (v[i] > count)
		{
			std::cout << count << std::endl;
			return 0;
		}
		count += v[i];
	}
	std::cout << count << std::endl;
	return 0;
}
