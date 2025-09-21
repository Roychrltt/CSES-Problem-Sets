#include <bits/stdc++.h>

const int MOD = 1e9 + 7;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n, k;
	std::cin >> n >> k;
	std::vector<std::vector<int>> arr;

	int root = std::sqrt(n);
	int row = 0, col = 0, count = 0;


	std::vector<int> vec;
	for (int i = 1; i <= n; i++)
	{
		if (count > root)
		{
			count = 0;
			arr.push_back(vec);
			vec.clear();
		}
		vec.push_back(i);
		count++;
	}
	if (!vec.empty()) arr.push_back(vec);
	for (int i = 0; i < n; i++)
	{
		int j = k % (n - i);
		while (j)
		{
			if (col + j < arr[row].size())
			{
				col += j;
				j = 0;
			}
			else
			{
				j -= arr[row].size() - col;
				col = 0;
				row++;
			}
			if (row >= arr.size()) row = 0;
		}
		while (arr[row].size() <= col)
		{
			col = 0;
			row++;
			if (row >= arr.size()) row = 0;
		}
		std::cout << arr[row][col] << " ";
		if (i != n - 1)
		{
			arr[row].erase(arr[row].begin() + col);
			while (arr[row].size() <= col)
			{
				col = 0;
				row++;
				if (row >= arr.size()) row = 0;
			}
		}
	}
	return 0;
}
