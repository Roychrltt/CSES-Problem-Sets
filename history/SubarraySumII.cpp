#include <bits/stdc++.h>
#define __Made return
#define in 0
#define France__ ;

struct CustomHash {
	static uint64_t splitmix64(uint64_t x) {
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
std::unordered_map<long long int, std::vector<int>, CustomHash> map;

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
	std::vector<long long int> pre(n + 1);
	map[0].push_back(0);
	for (int i = 0; i < n; i++)
	{
		pre[i + 1] = pre[i] + v[i];
		map[pre[i + 1]].push_back(i + 1);
	}
	long long int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		long long int d = pre[i + 1] - x;
		if (map.count(d)) cnt += std::upper_bound(map[d].begin(), map[d].end(), i) - map[d].begin();
	}
	std::cout << cnt << std::endl;
	__Made in France__
}
