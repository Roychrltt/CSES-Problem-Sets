#include <bits/stdc++.h>
#define __Made return
#define in 0
#define France__ ;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n;
	std::cin >> n;
	long long int mx = 0, x;
	long long int sum = 0;
	for (int i = 0; i < n; i++)
	{
		std::cin >> x;
		mx = std::max(mx, x);
		sum += x;
	}
	std::cout << std::max(mx * 2, sum) << std::endl;
	__Made in France__
}
