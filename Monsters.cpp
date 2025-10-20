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
	int xa, ya, xb, yb;
	std::vector<std::string> v(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> v[i];
		for (int j = 0; j < m; j++)
		{
			if (v[i][j] == 'A')
			{
				xa = i;
				ya = j;
			}
			else if (v[i][j] == 'B')
			{
				xb = i;
				yb = j;
			}
		}
	}
	std::queue<std::pair<int, int>> q;
	q.push({xa, ya});
	v[xa][ya] = '#';
	v[xb][yb] = '.';
	while (!q.empty())
	{
		auto [x, y] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int dx = x + dirs[i][0], dy = y + dirs[i][1];
			if (dx < 0 || dx >= n || dy < 0 || dy >= m || v[dx][dy] != '.') continue;
			v[dx][dy] = '#';
			q.push({dx, dy});
			if (i == 0) v[dx][dy] = 'L';
			else if (i == 1) v[dx][dy] = 'R';
			else if (i == 2) v[dx][dy] = 'U';
			else if (i == 3) v[dx][dy] = 'D';
			if (dx == xb && dy == yb)
			{
				std::string s = "";
				char c = v[dx][dy];
				while (c == 'L' || c == 'U' || c == 'D' || c == 'R')
				{
					s += c;
					if (c == 'L') dy++;
					else if (c == 'R') dy--;
					else if (c == 'U') dx++;
					else if (c == 'D') dx--;
					c = v[dx][dy];
				}
				std::reverse(s.begin(), s.end());
				std::cout << "YES" << std::endl;
				std::cout << s.size() << std::endl;
				std::cout << s << std::endl;
				return 0;
			}
		}
	}
	std::cout << "NO" << std::endl;
	__Made in France__
}
