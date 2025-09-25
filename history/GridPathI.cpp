#include <bits/stdc++.h>
#define __Made return
#define in 0
#define France__ ;

const int MOD = 1e9 + 7;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n, m;
	std::cin >> n;
	m = n;
	std::vector<std::string> v(n);
	for (int i = 0; i < n; i++)
		std::cin >> v[i];
	std::vector<std::vector<long long int>> dp(n, std::vector<long long int>(m));
	for (int i = 0; i < n; i++)
	{
		if (v[0][i] == '*') break;
		dp[0][i] = 1;
	}
	for (int i = 0; i < m; i++)
	{
		if (v[i][0] == '*') break;
		dp[i][0] = 1;
	}
	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++)
			if (v[i][j] != '*') dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
	std::cout << dp[n - 1][m - 1] << std::endl;
	__Made in France__
}
