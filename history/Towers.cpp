#include <bits/stdc++.h>
#define __Made return
#define in 0
#define France__ ;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n;
	std::cin >> n;
	std::multiset<int> set;
	for (int i = 0; i < n; i++) {
		int x;
		std::cin >> x;

		auto it = set.upper_bound(x);
		if (it == set.end())
			set.insert(x);
		else
		{
			set.erase(it);
			set.insert(x);
		}
	}
	std::cout << set.size() << std::endl;
	__Made in France__
}
