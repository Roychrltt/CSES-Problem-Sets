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
	std::vector<std::vector<int>> next(n + 1, std::vector<int>());
	DSU dsu(n + 1);
	while (m--)
	{
		int a, b;
		std::cin >> a >> b;
		next[a].push_back(b);
		next[b].push_back(a);
		dsu.unite(a, b);
	}
	std::set<int> set;
	for (int i = 1; i <= n; i++)
		set.insert(dsu.find(i));
	std::vector<int> vis(n + 1);
	std::queue<int> q;
	for (int x : set)
	{
		vis[x] = 1;
		q.push(x);
	}
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		for (int x : next[node])
		{
			if (!vis[x])
			{
				q.push(x);
				vis[x] = vis[node] == 1 ? 2 : 1;
			}
			if (vis[x] == vis[node])
			{
				std::cout << "IMPOSSIBLE" << std::endl;
				return 0;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (vis[i] == 0) vis[i] = 1;
	}
	std::copy(vis.begin() + 1, vis.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	__Made in France__
}
