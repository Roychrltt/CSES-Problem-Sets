#include <bits/stdc++.h>
#define __Made return
#define in 0
#define France__ ;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	int n, m;
	std::cin >> n >> m;
	std::vector<std::string> v(n);
	for (int i = 0; i < n; i++)
		std::cin >> v[i];
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (v[i][j] == '.')
			{
				cnt++;
				std::queue<std::pair<int, int>> q;
				q.push({i, j});
				v[i][j] = '#';
				while (!q.empty())
				{
					auto [x, y] = q.front();
					q.pop();
					for (auto& d : dirs)
					{
						int dx = x + d[0], dy = y + d[1];
						if (dx >= 0 && dx < n && dy >= 0 && dy < m && v[dx][dy] == '.')
						{
							q.push({dx, dy});
							v[dx][dy] = '#';
						}
					}
				}
			}
		}
	}
	std::cout << cnt << std::endl;
	__Made in France__
}
