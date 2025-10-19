#include <bits/stdc++.h>
#define __Made return
#define in 0
#define France__ ;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	long long int n, x;
	std::cin >> n >> x;
	std::vector<long long int> v(n);
	for (int i = 0; i < n; i++)
		std::cin >> v[i];
	std::vector<std::pair<int, long long int>> dp(1 << n);
	dp[0] = {1, 0};
	for (int i = 1; i < (1 << n); i++)
	{
		dp[i] = {21, 0};
		for (int j = 0; j < n; j++)
		{
			if ((i >> j) & 1)
			{
				auto [ride, w] = dp[i ^ (1 << j)];
				if (w + v[j] > x)
				{
					ride++;
					w = std::min(w, v[j]);
				}
				else w += v[j];
				dp[i] = std::min(dp[i], {ride, w});
			}
		}
	}
	std::cout << dp[(1 << n) - 1].first << std::endl;
	__Made in France__
}
