#include <bits/stdc++.h>
#define __Made return
#define in 0
#define France__ ;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n, x;
	std::cin >> n >> x;
	std::vector<int> v(n);
	for (int i = 0; i < n; i++)
		std::cin >> v[i];
	std::vector<int> dp(x + 1, INT_MAX);
	dp[0] = 0;
	for (int i = 1; i <= x; i++)
	{
		for (int j = 0; j < n; j++)
			if (i >= v[j] && dp[i - v[j]] < INT_MAX) dp[i] = std::min(dp[i], dp[i - v[j]] + 1);
	}
	std::cout << (dp[x] == INT_MAX ? -1 : dp[x]) << std::endl;
	__Made in France__
}
