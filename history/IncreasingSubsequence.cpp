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
	std::vector<int> dp;
	for (int i = 0; i < n; i++)
	{
		int x;
		std::cin >> x;
		auto it = std::lower_bound(dp.begin(), dp.end(), x);
		if (it == dp.end()) dp.push_back(x);
		else *it = x;
	}
	std::cout << dp.size() << std::endl;

	__Made in France__
}
