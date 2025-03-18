#include <bits/stdc++.h>
#define __Made return
#define in 0
#define France__ ;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n, m;
	std::cin >> n >> m;
	std::set<int> lights = {0, n};
	std::multiset<int> dist = {n};
	while (m--)
	{
		int p;
		std::cin >> p;
		auto it2 = lights.upper_bound(p);
		auto it1 = prev(it2);
		dist.erase(dist.find(*it2 - *it1));
		dist.insert(*it2 - p);
		dist.insert(p - *it1);
		auto it = dist.end();
		it--;
		lights.insert(p);
		std::cout << *it << " ";
	}
	__Made in France__
}
