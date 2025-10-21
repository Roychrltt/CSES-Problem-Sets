#include <bits/stdc++.h>
#define __Made return
#define in 0
#define France__ ;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int dirs[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
	int n, m;
	std::cin >> n >> m;
	int xa, ya;
	std::vector<std::string> v(n);
	std::vector<std::vector<int>> grid(n, std::vector<int>(m));
	std::queue<std::vector<int>> q;
	std::queue<std::pair<int, int>> qm;
	for (int i = 0; i < n; i++)
	{
		std::cin >> v[i];
		for (int j = 0; j < m; j++)
		{
			if (v[i][j] == 'M')
			{
				qm.push({i, j});
				grid[i][j] = 0;
			}
			else if (v[i][j] == 'A')
			{
				xa = i;
				ya = j;
				grid[i][j] = 1e8;
			}
			else if (v[i][j] == '.') grid[i][j] = 1e8;
			else if (v[i][j] == '#') grid[i][j] = -1;
		}
	}
	v[xa][ya] = '#';
	q.push({xa, ya, 0});
	while (!qm.empty())
	{
		auto [x, y] = qm.front();
		qm.pop();
		for (int i = 0; i < 4; i++)
		{
			int dx = x + dirs[i][0], dy = y + dirs[i][1];
			if (dx < 0 || dx >= n || dy < 0 || dy >= m || grid[dx][dy] <= grid[x][y] + 1) continue;
			grid[dx][dy] = grid[x][y] + 1;
			qm.push({dx, dy});
		}
	}
	while (!q.empty())
	{
		auto vv = q.front();
		q.pop();
		int x = vv[0], y = vv[1], len = vv[2];
		for (int i = 0; i < 4; i++)
		{
			int dx = x + dirs[i][0], dy = y + dirs[i][1];
			if (dx < 0 || dx >= n || dy < 0 || dy >= m)
			{
				std::string s = "";
				char c = v[x][y];
				while (c == 'L' || c == 'U' || c == 'D' || c == 'R')
				{
					s += c;
					if (c == 'L') y++;
					else if (c == 'R') y--;
					else if (c == 'U') x++;
					else if (c == 'D') x--;
					c = v[x][y];
				}
				std::reverse(s.begin(), s.end());
				std::cout << "YES" << std::endl;
				std::cout << s.size() << std::endl;
				std::cout << s << std::endl;
				return 0;

			}
			if (v[dx][dy] != '.' || len + 1 >= grid[dx][dy]) continue;
			if (i == 0) v[dx][dy] = 'L';
			else if (i == 1) v[dx][dy] = 'R';
			else if (i == 2) v[dx][dy] = 'U';
			else if (i == 3) v[dx][dy] = 'D';
			q.push({dx, dy, len + 1});
		}
	}
	std::cout << "NO" << std::endl;
	__Made in France__
}
