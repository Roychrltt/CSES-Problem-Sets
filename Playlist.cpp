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
	std::vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> v[i];
	}
	std::map<int, int> map;
	int l = 0, r = 0, ans = 1, count = 0;
	while (r < n)
	{
		if (map.find(v[r]) == map.end() || map[v[r]] == 0)
		{
			count++;
			map[v[r]]++;
			r++;
		}
		else
		{
			ans = std::max(ans, count);
			count--;
			map[v[l]]--;
			l++;
		}
	}
	ans = std::max(ans, count);
	std::cout << ans << std::endl;
	__Made in France__
}
