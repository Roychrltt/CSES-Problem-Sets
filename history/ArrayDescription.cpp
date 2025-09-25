#include <bits/stdc++.h>
#define __Made return
#define in 0
#define France__ ;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	long long int n, m;
	std::cin >> n >> m;
	std::vector<long long int> v(n);
	for (int i = 0; i < n; i++)
		std::cin >> v[i];
	std::vector<std::vector<long long int>> dp(n, std::vector<long long int>(m + 2));
	const int MOD = 1e9 + 7;
	if (v[0] == 0)
	{
		for (int i = 1; i <= m; i++)
			dp[0][i] = 1;
	}
	else dp[0][v[0]] = 1;
	for (int i = 1; i < n; i++)
	{
		if (v[i] == 0)
		{
			for (int j = 1; j <= m; j++)
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % MOD;
		}
		else
		{
			dp[i][v[i]] = (dp[i - 1][v[i] - 1] + dp[i - 1][v[i]] + dp[i - 1][v[i] + 1]) % MOD;
		}
	}
	long long int ans = 0;
	for (long long int x : dp[n - 1]) ans = (ans + x) % MOD;
	std::cout << ans << std::endl;
	__Made in France__
}
