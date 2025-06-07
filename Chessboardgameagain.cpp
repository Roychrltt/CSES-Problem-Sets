#include <bits/stdc++.h>
#define __Made return
#define in 0
#define France__ ;

static std::map<std::pair<int, int>, int> cache;

static void solve(void)
{
	int n;
	std::cin >> n;
	int xorn = 0, r, c;
	auto nimber = [&](this auto&& nimber, int r, int c) -> int
	{
		if (cache.count({r, c})) return cache[{r, c}];

		if (r < 0 || c < 0 || r >= 15 || c >= 15) return -1;
		std::set<int> reachable{nimber(r - 2, c + 1), nimber(r - 2, c - 1), nimber(r + 1, c - 2), nimber(r - 1, c - 2)};
		int ret = 0;
		while (reachable.count(ret)) ret++;

		return cache[{r, c}] = ret;
	};
	for (int i = 0; i < n; i++)
	{
		std::cin >> r >> c;
		xorn ^= nimber(r - 1, c - 1);
	}
	std::cout << (xorn == 0 ? "Second" : "First") << std::endl;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int t;
	std::cin >> t;
	while (t--)
	{
		solve();
	}
	__Made in France__
}
