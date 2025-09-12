#include <bits/stdc++.h>
#define __Made return
#define in 0
#define France__ ;

static void solve(void)
{
	int n, a, b;
	std::cin >> n >> a >> b;
	if (a + b > n || a + b == 1 || (!a && b) || (!b && a))
	{
		std::cout << "NO" << std::endl;
		return;
	}
	std::cout << "YES" << std::endl;
	std::vector<int> v(n);
	std::iota(v.begin(), v.end(), 1);
	std::vector<int> vv(n);
	for (int i = 0; i < b; i++)
		vv[i] = i + a + 1;
	for (int i = b; i < a + b; i++)
		vv[i] = i - b + 1;
	for (int i = a + b; i < n; i++)
		vv[i] = v[i];
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	std::copy(vv.begin(), vv.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
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
