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
	std::vector<std::vector<int>> next(n + 1, std::vector<int>());
	while (m--)
	{
		int a, b;
		std::cin >> a >> b;
		next[a].push_back(b);
		next[b].push_back(a);
	}
	std::vector<int> vis(n + 1);
	vis[0] = vis[1] = -1;
	std::queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int node = q.front();
		if (node == n)
		{
			std::vector<int> ans;
			int cur = n;
			while (vis[cur] > 0)
			{
				ans.push_back(cur);
				cur = vis[cur];
			}
			ans.push_back(1);
			std::reverse(ans.begin(), ans.end());
			std::cout << ans.size() << std::endl;
			std::copy(ans.begin(), ans.end(), std::ostream_iterator<int>(std::cout, " "));
			std::cout << std::endl;
			return 0;
		}
		q.pop();
		for (int x : next[node])
		{
			if (!vis[x])
			{
				q.push(x);
				vis[x] = node;
			}
		}
	}
	std::cout << "IMPOSSIBLE" << std::endl;
	__Made in France__
}
