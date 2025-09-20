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
	std::vector<std::string> v(n);
	for (int i = 0; i < n; i++)
		std::cin >> v[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::set<char> set = {'A', 'B', 'C', 'D'};
			if (i > 0) set.erase(v[i - 1][j]);
			if (j > 0) set.erase(v[i][j - 1]);
			set.erase(v[i][j]);
			if (set.empty())
			{
				std::cout << "IMPOSSIBLE" << std::endl;
				return 0;
			}
			v[i][j] = *set.begin();
		}
	}
	for (auto& s : v) std::cout << s << std::endl;
	__Made in France__
}
