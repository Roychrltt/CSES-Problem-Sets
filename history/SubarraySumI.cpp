#include <bits/stdc++.h>
#define __Made return
#define in 0
#define France__ ;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	long long int n, x;
	std::cin >> n >> x;
	std::vector<int> v(n);
	for (int i = 0; i < n; i++)
		std::cin >> v[i];
	long long int sum = v[0];
	int cnt = 0, prev = 0;
	if (sum == x) cnt++;
	for (int i = 1; i < n; i++)
	{
		sum += v[i];
		while (sum > x) sum -= v[prev++];
		if (sum == x) cnt++;
	}
	std::cout << cnt << std::endl;
	__Made in France__
}
