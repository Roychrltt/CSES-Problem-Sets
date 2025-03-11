#include <bits/stdc++.h>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n;
	std::cin >> n;
	std::vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> v[i];
	}
	std::sort(v.begin(), v.end());
	if (n == 1)
	{
		std::cout << 0 << std::endl;
		return 0;
	}
	int mid = n % 2 == 1 ? v[n / 2] : (v[n / 2] + v[n / 2 - 1]) / 2;
	long long int sum = 0;
	for (int i : v) {
		sum += std::abs(i - mid);
	}
	std::cout << sum << std::endl;
	return 0;
}
