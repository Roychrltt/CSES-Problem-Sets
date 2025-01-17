#include <iostream>

const int MOD = 1e9 + 7;

int main()
{
	int n;
	std::cin >> n;
	long long ans = 1;
	long long base = 2;
	while (n > 0)
	{
		if (n % 2)
			ans = ans * base % MOD;
		base = base * base % MOD;
		n /= 2;
	}
	std::cout << ans << std::endl;
	return 0;
}
