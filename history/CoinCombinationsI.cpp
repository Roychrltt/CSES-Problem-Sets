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
	for (int i = 0; i < n; i++)
		if (v[i] <= x) dp[v[i]] = 1;
	for (int i = 1; i <= x; i++)
	{
		for (int j = 0; j < n; j++)
			if (i >= v[j]) dp[i] = (dp[i] + dp[i - v[j]]) % MOD;
	}
	std::cout << dp[x] << std::endl;
	__Made in France__
}
