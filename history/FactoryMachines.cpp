#include <bits/stdc++.h>
#define __Made return
#define in 0
#define France__ ;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n, k;
	std::cin >> n >> k;
	std::vector<int> v(n);
	for (int i = 0; i < n; i++)
		std::cin >> v[i];
	long long int r = 1ll * *min_element(v.begin(), v.end()) * k, l = 1;
	auto check = [&](long long int x) -> bool
	{
		long long int cnt = 0;
		for (int i : v) cnt += x / i;
		return cnt >= k;
	};
	while (l < r)
	{
		long long int mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	std::cout << l << std::endl;
	__Made in France__
}
