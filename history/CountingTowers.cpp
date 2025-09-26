#include <bits/stdc++.h>
#define __Made return
#define in 0
#define France__ ;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int t;
	std::cin >> t;
	const int MOD = 1e9 + 7;
	std::vector<long long int> a(1e6 + 1), b(1e6 + 1);
	a[1] = b[1] = 1;
	for (int i = 2; i < 1e6 + 1; i++)
	{
		a[i] = (2 * a[i - 1] + b[i - 1]) % MOD;
		b[i] = (4 * b[i - 1] + a[i - 1]) % MOD;
	}
	while (t--)
	{
		int n;
		std::cin >> n;
		std::cout << (a[n] + b[n]) % MOD << std::endl;
	}
	__Made in France__
}
