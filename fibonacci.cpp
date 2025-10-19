#include <bits/stdc++.h>
#define __Made return
#define in 0
#define France__ ;

const int MOD = 1e9 + 7;

long long int solve(long long int n)
{
	if (n < 2) return n;
	long long int a = 0, b = 1;
	for (int i = 1; i < n; i++)
	{
		long long int tmp = (a + b) % MOD;
		a = b;
		b = tmp;
	}
	return b;
}

// just a function to do matrix A * matrix B
void multiply(std::vector<std::vector<long long int>>& A, std::vector<std::vector<long long int>> &B)
{
	std::vector<std::vector<long long int>> C(2, std::vector<long long int>(2));

	C[0][0] = (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % MOD;
	C[0][1] = (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % MOD;
	C[1][0] = (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % MOD;
	C[1][1] = (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % MOD;

	A = C;
}

std::vector<std::vector<long long int>> matrixPower(std::vector<std::vector<long long int>>& M, int e)
{
	std::vector<std::vector<long long int>> ans = {{1, 0}, {0, 1}};
	while (e)
	{
		if (e & 1) multiply(ans, M);
		multiply(M, M);
		e >>= 1;
	}
	return ans;
}

long long int fibo(long long int n)
{
	if (n < 2) return n;
	std::vector<std::vector<long long int>> M = {{1, 1}, {1, 0}};
	std::vector<std::vector<long long int>> F = {{1, 0}, {0, 0}};
	std::vector<std::vector<long long int>> res = matrixPower(M, n - 1);
	multiply(res, F);
	return res[0][0] % MOD;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n = 1e6;
	auto start = std::chrono::high_resolution_clock::now();
	std::cout << solve(n) << std::endl;
	auto end = std::chrono::high_resolution_clock::now();

	double duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Execution Time: " << duration / 1e6 << " seconds\n";

	start = std::chrono::high_resolution_clock::now();
	std::cout << solve1(n) << std::endl;
	end = std::chrono::high_resolution_clock::now();

	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Execution Time: " << duration / 1e6 << " seconds\n";
	__Made in France__
}
