#include <iostream>
#include <vector>
#include <functional>

int main()
{
	int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	bool onPath[9][9] = {};
	for (int i = 0; i < 9; i++) {
		onPath[i][0] = true;
		onPath[i][8] = true;
		onPath[0][i] = true;
		onPath[8][i] = true;
	}
	
	std::string s;
	std::cin >> s;
	int p[48];
	for (int i = 0; i < 48; i++) {
		char c = s[i];
		if (c == 'R') p[i] = 0;
		else if (c == 'L') p[i] = 1;
		else if (c == 'D') p[i] = 2;
		else if (c == 'U') p[i] = 3;
		else p[i] = 4;
	}
	int ans = 0;
	std::function<void(int, int, int)> dfs = [&](int r, int c, int x) -> void
	{
		if (x == 48)
		{
			if (r == 7 && c == 1) ans++;
			return;
		}
		if (r == 7 && c == 1) return;
		if (onPath[r - 1][c] && onPath[r + 1][c] && !onPath[r][c - 1] && !onPath[r][c + 1]) return;
		if (onPath[r][c - 1] && onPath[r][c + 1] && !onPath[r - 1][c] && !onPath[r + 1][c]) return;
		onPath[r][c] = true;
		int d = p[x];
		if (d < 4)
		{
			int dr = r + dir[d][0];
			int dc = c + dir[d][1];
			if (!onPath[dr][dc])
				dfs(dr, dc, x + 1);
		}
		else
		{
			for (auto& a : dir)
			{
				int dr = r + a[0];
				int dc = c + a[1];
				if (!onPath[dr][dc])
					dfs(dr, dc, x + 1);
			}
		}
		onPath[r][c] = false;
		return;
	};
	dfs(1, 1, 0);
	std::cout << ans << std::endl;
	return 0;
}
