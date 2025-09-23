#include <bits/stdc++.h>
#define __Made return
#define in 0
#define France__ ;

const int MOD = 1e9 + 7;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n;
	std::cin >> n;
	std::vector<long long int> v(n + 1);
	v[1] = v[2] = v[3] = v[4] = v[5] = v[6] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 6 && j < i; j++)
			v[i] = (v[i] + v[i - j]) % MOD;
	}
	std::cout << v[n] << std::endl;
	__Made in France__
}
