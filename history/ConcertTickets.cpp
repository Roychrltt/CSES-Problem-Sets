#include <bits/stdc++.h>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n, m;
	std::cin >> n >> m;
	std::multiset<int> price;
	for (int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		price.insert(x);
	}
	for (int i = 0; i < m; ++i) {
		int x;
		std::cin >> x;
		auto it = price.upper_bound(x);
		if (it != price.begin())
		{
			it--;
			std::cout << *it << std::endl;
			price.erase(it);
		}
		else
			std::cout << -1 << std::endl;
	}

	return 0;
}
