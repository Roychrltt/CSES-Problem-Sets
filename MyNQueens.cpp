#include <bits/stdc++.h>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	
	int n;
	std::cin >> n;
	std::vector<std::string> v(n);
	std::vector<int> col(n), diago1(2 * n - 1), diago2(2 * n - 1);
	int ans = 0;
	auto dfs = [&](this auto&& dfs, int r) -> void
	{
		if (r == n)
		{
			ans++;
			return;
		}
		for (int i = 0; i < n; i++) {
			int rc = r - i + n - 1;
			if (col[i] || diago1[r + i] || diago2[rc]) continue;
			col[i] = 1, diago1[r + i] = 1, diago2[rc] = 1;
			dfs(r + 1);
			col[i] = 0, diago1[r + i] = 0, diago2[rc] = 0;
		}
	};
	dfs(0);
	std::cout << "For case N == " << n << ", there are altogether " << ans << " possible solutions." << std::endl;
	return 0;
}
