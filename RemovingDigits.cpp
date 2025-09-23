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
	std::vector<int> dp(n + 1, INT_MAX);
	dp[n] = 0;
	for (int i = 0; i < n; i++)
		dp[i][1] = INT_MAX;
	for (int i = n; i >= 0; i--)
	{
		int tmp = i;
		while (tmp)
		{
			int d = tmp % 10;
			tmp /= 10;
			if (i + d <= n) dp[i] = std::min(dp[i], dp[i + d] + 1);
		}
	}
	std::cout << dp[0] << std::endl;
	__Made in France__
}
