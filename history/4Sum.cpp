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
std::unordered_map<int, std::pair<int, int>, CustomHash> map;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n, x;
	std::cin >> n >> x;
	std::vector<int> v(n);
	for (int i = 0; i < n; i++)
		std::cin >> v[i];
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			map[v[i] + v[j]] = {i, j};
		}
	}
	for (int i = 0; i < n - 3; i++)
	{
		for (int j = i + 1; j < n - 2; j++)
		{
			int d = x - v[i] - v[j];
			if (map.count(d) && map[d].first > j)
			{
				std::cout << i + 1 << " " << j + 1 << " " << map[d].first + 1 << " " << map[d].second + 1 << std::endl;
				return 0;
			}
		}
	}
	std::cout << "IMPOSSIBLE" << std::endl;
	__Made in France__
}
