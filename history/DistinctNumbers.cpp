#include <bits/stdc++.h>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n;
	std::cin >> n;
	std::set<int> set;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		int x;
		std::cin >> x;
		set.insert(x);
	}
	std::cout << set.size() << std::endl;
	return 0;
}
