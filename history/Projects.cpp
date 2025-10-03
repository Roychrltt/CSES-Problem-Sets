#include <bits/stdc++.h>
#define __Made return
#define in 0
#define France__ ;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	long long int n;
	std::cin >> n;
	std::vector<std::vector<long long int>> v(n, std::vector<long long int>(3));
	for (long long int i = 0; i < n; i++) 
		std::cin >> v[i][0] >> v[i][1] >> v[i][2];
	std::sort(v.begin(), v.end());
	std::vector<long long int> dp(n);
	for (long long int i = n - 1; i >= 0; i--) 
	{
		dp[i] = v[i][2];
		long long int end = v[i][1];
		long long int next = (std::lower_bound(v.begin() + i + 1, v.end(), end + 1, [&](const auto& e, long long int time)
					{ return e[0] < time; }) - v.begin());
		if (next < n) dp[i] += dp[next];
		if (i < n - 1) dp[i] = std::max(dp[i], dp[i + 1]);
	}
	std::cout << dp[0] << std::endl;
	__Made in France__
}
