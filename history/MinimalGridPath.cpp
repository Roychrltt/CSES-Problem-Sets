#include <bits/stdc++.h>
#define __Made return
#define in 0
#define France__ ;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	std::vector<std::string> v(n);
	for (int i = 0; i < n; i++) std::cin >> v[i];
	std::string ans = std::string(1, v[0][0]);
	std::vector<std::vector<int>> vis(n, std::vector<int>(n));
	std::queue<std::pair<int, int>> q;
	q.push({0, 0});
	while (!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		q.pop();
		if (v[x][y] > ans[x + y]) continue;

		if (x < n - 1 && !vis[x + 1][y])
		{
			vis[x + 1][y] = 1;
			if (ans.size() < x + y + 2)
			{
				ans += v[x + 1][y];
				q.push({x + 1, y});
			}
			else if (ans.back() >= v[x + 1][y])
			{
				ans.back() = v[x + 1][y];
				q.push({x + 1, y});
			}
		}
		if (y < n - 1 && !vis[x][y + 1])
		{
			vis[x][y + 1] = 1;
			if (ans.size() < x + y + 2)
			{
				ans += v[x][y + 1];
				q.push({x, y + 1});
			}
			else if (ans.back() >= v[x][y + 1])
			{
				ans.back() = v[x][y + 1];
				q.push({x, y + 1});
			}
		}
	}
	std::cout << ans << std::endl;
	__Made in France__
}
