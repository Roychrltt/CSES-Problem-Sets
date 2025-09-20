#include <bits/stdc++.h>
#define __Made return
#define in 0
#define France__ ;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> v(n);
	std::vector<int> map(n + 2);
	map[0] = -1, map[n + 1] = n;
	for (int i = 0; i < n; i++) {
		std::cin >> v[i];
		map[v[i]] = i;
	}
	int count = 1;
	for (int x : v)
		if (map[x] < map[x - 1])
			count++;

	while (m--)
	{
		int a, b;
		std::cin >> a >> b;
		a--, b--;
		int num1 = v[a], num2 = v[b];
		std::set<int> set = {num1, num1 - 1, num1 + 1, num2, num2 - 1, num2 + 1};
		for (int x : set) 
			if (x >= 1 && x <= n) 
				if (map[x] > map[x + 1]) count--;

		std::swap(v[a], v[b]);
		std::swap(map[num1], map[num2]);

		for (int x : set) 
			if (x >= 1 && x <= n) 
				if (map[x] > map[x + 1]) count++;
		std::cout << count << std::endl;
	}
	__Made in France__
}
