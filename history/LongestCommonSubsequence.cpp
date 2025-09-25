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
	std::vector<int> a(n), b(m);
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
	for (int i = 0; i < m; i++)
		std::cin >> b[i];
	std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));
	int idx1 = -1, idx2 = -1, cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
			if (dp[i][j] > cnt)
			{
				cnt = dp[i][j];
				idx1 = i;
				idx2 = j;
			}
		}
	}
	std::cout << cnt << std::endl;
	if (cnt)
	{
		std::vector<int> ans;
		int i = n, j = m;
		while (i && j)
		{
			if (a[i - 1] == b[j - 1])
			{
				ans.push_back(a[i - 1]);
				i--;
				j--;
			}
			else if (dp[i - 1][j] > dp[i][j - 1]) i--;
			else j--;
		}
		std::reverse(ans.begin(), ans.end());
		std::copy(ans.begin(), ans.end(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;
	}
	__Made in France__
}
