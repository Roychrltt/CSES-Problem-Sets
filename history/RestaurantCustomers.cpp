#include <bits/stdc++.h>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n;
	std::cin >> n;
	std::vector<int> come(n);
	std::vector<int> leave(n);
	for (int i = 0; i < n; i++) {
		std::cin >> come[i] >> leave[i];
	}
	std::sort(come.begin(), come.end());
	std::sort(leave.begin(), leave.end());
	int ans = 1;
	for (int i = 0; i < n; i++) {
		auto it = std::lower_bound(come.begin(), come.end(), leave[i]);
		int len = it - come.begin() - i;
		ans = std::max(ans, len);
	}
	std::cout << ans << std::endl;
	return 0;
}
