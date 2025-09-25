#include <bits/stdc++.h>
#define __Made return
#define in 0
#define France__ ;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n, C;
	std::cin >> n >> C;
	std::vector<int> w(n), v(n);
	for (int i = 0; i < n; i++)
		std::cin >> w[i];
	for (int i = 0; i < n; i++)
		std::cin >> v[i];
	std::vector<int> dp(C + 1);
	for (int i = 1; i <= n; i++)
	{
		for (int j = C; j > 0; j--)
		{
			if (j < w[i - 1]) continue;
			dp[j] = std::maC(dp[j], dp[j - w[i - 1]] + v[i - 1]);
		}
	}
	std::cout << dp[C] << std::endl;
	__Made in France__
}
