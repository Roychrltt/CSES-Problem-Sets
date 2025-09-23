#include <bits/stdc++.h>
#define __Made return
#define in 0
#define France__ ;

class SparseTable
{
	std::vector<std::vector<long long int>> st;
	std::vector<long long int> log;
	int n;

	public:

	SparseTable(const std::vector<long long int>& v) {
		n = v.size();
		int K = std::bit_width((unsigned int)n);

		st.assign(K, std::vector<long long int>(n));
		log.assign(n + 1, 0);

		for (int i = 2; i <= n; i++)
			log[i] = log[i / 2] + 1;

		for (int i = 0; i < n; i++)
			st[0][i] = v[i];

		for (int k = 1; k < K; k++)
			for (int i = 0; i + (1 << k) <= n; i++)
				st[k][i] = std::max(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
	}

	long long int query(int l, int r) {
		r = std::min(r, n - 1);
		int j = log[r - l + 1];
		return std::max(st[j][l], st[j][r - (1 << j) + 1]);
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	int n, a, b;
	std::cin >> n >> a >> b;
	std::vector<int> v(n);
	for (int i = 0; i < n; i++)
		std::cin >> v[i];
	std::vector<long long int> pre(n + 1);
	for (int i = 0; i < n; i++)
		pre[i + 1] = pre[i] + v[i];
	SparseTable st(pre);
	long long int ans = std::numeric_limits<long long int>::min();
	for (int i = 0; i < n - a + 1; i++)
	{
		long long int mx = st.query(i + a, i + b);
		ans = std::max(ans, mx - pre[i]);
	}
	std::cout << ans << std::endl;
	__Made in France__
}
