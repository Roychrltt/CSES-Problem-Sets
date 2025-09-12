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
	std::vector<std::vector<int>> v(n, std::vector<int>(n, INT_MAX));
	v[0][0] = 0, v[0][1] = 3, v[0][2] = 2, v[0][3] = 3;
	v[1][0] = 3, v[1][1] = 4, v[1][2] = 1, v[1][3] = 2;
	v[2][0] = 2, v[2][1] = 1, v[2][2] = 4, v[2][3] = 3;
	v[3][0] = 3, v[3][1] = 2, v[3][2] = 3, v[3][3] = 2;
	if (n == 4)
	{
		v[3][0] = 5, v[0][1] = 3, v[0][2] = 2, v[0][3] = 5;
	}
	int i = 4;
	while (i < n)
	{
		int r = 0, c = i;
		while (r <= i)
		{
			if (r >= 1) v[r][c] = std::min(v[r][c], v[r - 1][c - 2] + 1);
			if (r >= 2) v[r][c] = std::min(v[r][c], v[r - 2][c - 1] + 1);
			if (r <= i - 3) v[r][c] = std::min(v[r][c], v[r + 2][c - 1] + 1);
			if (r <= i - 2) v[r][c] = std::min(v[r][c], v[r + 1][c - 2] + 1);
			r++;
		}
		r = i, c = 0;
		while (c <= i)
		{
			if (c >= 1) v[r][c] = std::min(v[r][c], v[r - 2][c - 1] + 1);
			if (c >= 2) v[r][c] = std::min(v[r][c], v[r - 1][c - 2] + 1);
			if (c <= i - 3) v[r][c] = std::min(v[r][c], v[r - 1][c + 2] + 1);
			if (c <= i - 2) v[r][c] = std::min(v[r][c], v[r - 2][c + 1] + 1);
			c++;
		}
		i++;
	}
	for (auto &row : v)
	{
		for (int i : row) std::cout << i << " ";
		std::cout << std::endl;
	}
	__Made in France__
}
