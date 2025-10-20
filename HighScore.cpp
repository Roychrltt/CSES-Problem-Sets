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
	std::vector<std::vector<std::pair<long long int, long long int>>> next(n + 1, std::vector<std::pair<long long int, long long int>>());
	while (m--)
	{
		long long int a, b, c;
		std::cin >> a >> b >> c;
		next[a].push_back({b, c});
	}
	std::vector<long long int> vis(n + 1, LLONG_MIN);
	vis[1] = 0;
	std::queue<long long int> q;
	q.push(1);
	while (!q.empty())
	{
		long long int x = q.front();
		q.pop();
		for (auto& [a, b] : next[x])
		{
			long long int s = vis[x] + b;
			if (s > vis[a])
			{
				q.push(a);
				vis[a] = s;
			}
		}
	}
	std::cout << vis[n] << std::endl;
	__Made in France__
}
