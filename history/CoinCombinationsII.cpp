#include <bits/stdc++.h>
#define __Made return
#define in 0
#define France__ ;

const int MOD = 1e9 + 7;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	
	int n, x;
	std::cin >> n >> x;
	std::vector<int> v(n);
	for (int i = 0; i < n; i++)
		std::cin >> v[i];
	std::vector<long long int> dp(x + 1);
	dp[0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = v[i]; j <= x; j++)
			dp[j] = (dp[j] + dp[j - v[i]]) % MOD;
	}
	std::cout << dp[x] << std::endl;
	__Made in France__
}
