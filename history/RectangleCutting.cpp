#include <bits/stdc++.h>
#define __Made return
#define in 0
#define France__ ;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int a, b;
	std::cin >> a >> b;
	std::vector<std::vector<int>> dp(a + 1, std::vector<int>(b + 1, 1e9));
	for (int i = 0; i <= a; i++)
	{
		for (int j = 0; j <= b; j++)
		{
			if (i == j) dp[i][j] = 0;
			else
			{
				for (int k = 1; k < j; k++)
					dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
				for (int k = 1; k < i; k++)
					dp[i][j] = std::min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
			}
		}
	}
	std::cout << dp[a][b] << std::endl;
	__Made in France__
}
