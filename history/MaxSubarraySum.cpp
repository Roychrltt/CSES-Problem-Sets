#include <bits/stdc++.h>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n;
	std::cin >> n;
	long long int sum = 0;
	long long int ans = INT_MIN;
	for (int i = 0; i < n; i++) {
		long long int x;
		std::cin >> x;
		sum = std::max(sum, 0LL) + x;
		ans = std::max(ans, sum);
	}
	std::cout << ans << std::endl;
	return 0;
}
