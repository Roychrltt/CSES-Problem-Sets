#include <bits/stdc++.h>
#define __Made return
#define in 0
#define France__ ;

int grid[100][100] = {0};
int pow2[9] = {0,1,2,4,8,16,32,64,128};

void build(int r, int c)
{
	int i = 0, j = 0;
	while (pow2[i] <= r) i++;
	i--;
	while (pow2[j] <= c) j++;
	j--;

	if (i == j) grid[r][c] = grid[r - pow2[i]][c - pow2[j]];
	else if (i > j) grid[r][c] = grid[r - pow2[i]][c] + pow2[i];
	else grid[r][c] = grid[r][c - pow2[j]] + pow2[j];
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			build(i, j);
			std::cout << grid[i][j] << " ";
		}
		std::cout << std::endl;
	}
	__Made in France__
}
