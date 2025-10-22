#include <bits/stdc++.h>
#define __Made return
#define in 0
#define France__ ;

std::vector<std::vector<int>> g;
std::vector<int> vis;
std::vector<int> cycle;
int start_node = -1;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n, m;
	std::cin >> n >> m;
	g.assign(n + 1, {});
	vis.assign(n + 1, -1);
		std::function<int(int, int)> dfs = [&](int node, int parent)
		{
		if (vis[node] != -1)
		{
			start_node = node;
			cycle.push_back(node);
			return 1;
		}

		vis[node] = 1;

		for (int nxt : g[node])
		{
			if (nxt == parent) continue;

			int state = dfs(nxt, node);

			if (state == 1)
			{
				cycle.push_back(node);
				if (node == start_node) return 2;
				else return 1;
			}
			else if (state == 2) return 2;
		}

		vis[node] = 2;
		return 0;
	};
	for (int i = 0; i < m; i++)
	{
		int a, b;
		std::cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		if (vis[i] == -1 && dfs(i, -1))
		{
			std::reverse(cycle.begin(), cycle.end());
			std::cout << cycle.size() << std::endl;
			for (int x : cycle)
				std::cout << x << " ";
			std::cout << std::endl;
			return 0;
		}
	}
	std::cout << "IMPOSSIBLE" << std::endl;
	__Made in France__
}
