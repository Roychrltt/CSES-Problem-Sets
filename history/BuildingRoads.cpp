#include <bits/stdc++.h>
#define __Made return
#define in 0
#define France__ ;

class DSU {
	public:

		std::vector<int> v1, v2;

		// number of nodes, better do n + 1
		DSU(int n)
		{
			v1.resize(n);
			v2.resize(n, 0);
			for (int i = 0; i < n; ++i)
				v1[i] = i;
		}

		int find(int i)
		{
			if (v1[i] != i)
				v1[i] = find(v1[i]);
			return v1[i];
		}


		void unite(int i, int k)
		{
			int a = find(i);
			int b = find(k);
			if (a != b)
			{
				if (v2[a] > v2[b])
					v1[b] = a;
				else if (v2[a] < v2[b])
					v1[a] = b;
				else
				{
					v1[b] = a;
					v2[a]++;
				}
			}
		}

		bool is_same_set(int a, int b)
		{
			return find(a) == find(b);
		}
};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n, m;
	std::cin >> n >> m;
	DSU dsu(n + 1);
	while (m--)
	{
		int a, b;
		std::cin >> a >> b;
		dsu.unite(a, b);
	}
	int cnt = 0;
	std::set<int> set;
	for (int i = 1; i <= n; i++)
		set.insert(dsu.find(i));
	std::vector<int> nodes(set.begin(), set.end());
	std::cout << nodes.size() - 1 << std::endl;
	for (int i = 0; i < nodes.size() - 1; i++)
		std::cout << nodes[i] << " " << nodes.back() << std::endl;
	__Made in France__
}
