#include <bits/stdc++.h>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n, x;
	std::cin >> n >> x;
	std::vector<std::vector<int>> v(n, std::vector<int>(2));
	for (int i = 0; i < n; i++) {
		std::cin >> v[i][0];
		v[i][1] = i + 1;
	}
	std::sort(v.begin(), v.end());
	std::unordered_map<int, int> map;
	for (int i = 0; i < n; i++) {
		if (map.count(x - v[i][0]) > 0)
		{
			std::cout << map[x - v[i][0]] << " " << v[i][1] << std::endl;
			return 0;
		}
		map[v[i][0]] = v[i][1];
		if (v[i][0] > x) break;
	}
	std::cout << "IMPOSSIBLE" << std::endl;
	return 0;
}
