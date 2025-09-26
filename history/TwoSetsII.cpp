#include <bits/stdc++.h>
#define __Made return
#define in 0
#define France__ ;

const long long int MOD = 1000000007;

long long int modpow(long long int a, long long int e, long long int m) {
	long long int r = 1;
	while (e)
	{
		if (e & 1) r = r * a % m;
		a = a * a % m;
		e >>= 1;
	}
	return r;
}

// Fermat's little theorem: a^(m-2) ≡ a^(-1) (mod m), works since MOD is prime
long long int modinv(long long int a, long long m) {
	return modpow(a, m - 2, m);
}

// a / b % m = a * (b^(m - 2)) % m
long long int moddiv(long long int a, long long int b, long long int m) {
	return a % m * modinv(b, m) % m;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n;
	std::cin >> n;
	int sum = n * (n + 1) / 2;
	if (sum & 1)
	{
		std::cout << 0 << std::endl;
		return 0;
	}
	std::vector<long long int> dp(sum + 1);
	const int MOD = 1e9 + 7;
	dp[0] = 1;
	for (int i = 1; i <= n; i++) 
	{
		for (int j = sum; j >= i; j--) 
		{
			dp[j] = (dp[j] + dp[j - i]) % MOD;
		}
	}
	std::cout << moddiv(dp[sum / 2], 2, MOD) << std::endl;
	__Made in France__
}
