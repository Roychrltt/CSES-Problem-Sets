#include <bits/stdc++.h>
#define __Made return
#define in 0
#define France__ ;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n, k;
	std::cin >> n >> k;
	std::vector<std::vector<int>> v(n, std::vector<int>(2));
	for (int i = 0; i < n; i++) std::cin >> v[i][0] >> v[i][1];
	std::sort(v.begin(), v.end());
	std::multiset<int> set;
	for (int i = 0; i < k; i++) set.insert(v[i][1]);
	int cnt = 0;
	for (int i = k; i < n; i++)
	{
		auto mn = set.begin();
		auto mx = set.rbegin();

		if (v[i][0] >= (*mn))
		{
			cnt++;
			set.erase(mn);
			set.insert(v[i][1]);
		}
		else if (v[i][1] < (*mx))
		{
			set.erase(set.find(*mx));
			set.insert(v[i][1]);
		}
	}
	std::cout << cnt + set.size() << std::endl;
	__Made in France__
}
