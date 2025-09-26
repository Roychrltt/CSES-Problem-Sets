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
	std::vector<int> coins(n);
	for (int i = 0; i < n; i++)
		std::cin >> coins[i];
	int sum = std::accumulate(coins.begin(), coins.end(), 0);
	std::vector<int> dp(sum + 1);
	dp[0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = sum; j >= coins[i]; j--)
		{
			if (dp[j - coins[i]]) dp[j] = 1;
		}
	}
	dp[0] = 0;
	std::cout << std::accumulate(dp.begin(), dp.end(), 0) << std::endl;
	for (int i = 1; i < sum + 1; i++)
		if (dp[i]) std::cout << i << " ";
	std::cout << std::endl;
	__Made in France__
}
