#include <bits/stdc++.h>
#define __Made return
#define in 0
#define France__ ;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	std::string s, t;
	std::cin >> s >> t;
	int n = s.length(), m = t.length();
	std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (i == 0) dp[i][j] = j;
			else if (j == 0) dp[i][j] = i;
			else if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = std::min({dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1, dp[i][j - 1] + 1});
		}
	}
	std::cout << dp[n][m] << std::endl;
	__Made in France__
}
