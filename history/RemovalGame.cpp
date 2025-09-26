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
	std::vector<long long int> v(n);
	for (int i = 0; i < n; i++) std::cin >> v[i];
	long long int sum = std::accumulate(v.begin(), v.end(), 0ll);
	std::vector<std::vector<long long int>> dp(n, std::vector<long long int>(n));
	for (int l = n - 1; l >= 0; l--)
	{
		for (int r = l; r < n; r++)
		{
			if (l == r) dp[l][r] = v[l];
			else
			{
				dp[l][r] = std::max(v[l] - dp[l + 1][r], v[r] - dp[l][r - 1]);
			}
		}
	}
	std::cout << (sum + dp[0][n - 1]) / 2 << std::endl;
	__Made in France__
}
