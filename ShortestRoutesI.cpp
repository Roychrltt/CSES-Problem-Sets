#include <bits/stdc++.h>
#define __Made return
#define in 0
#define France__ ;

using pii = std::pair<long long int, long long int>;
void dijkstra(int start, int dst, const std::vector<std::vector<pii>>& adj) {
	std::vector<long long int> dist(dst + 1, LONG_MAX); 
	std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;

	dist[start] = 0;
	pq.push({0, start});

	while (!pq.empty()) {
		auto [d, node] = pq.top();
		pq.pop();

		if (d > dist[node]) continue; 

		for (const auto& [neighbour, time] : adj[node]) {
			if (dist[node] + time < dist[neighbour]) {
				dist[neighbour] = dist[node] + time;
				pq.push({dist[neighbour], neighbour});
			}
		}
	}

	for (int i = 1; i <= dst; i++)
		std::cout << dist[i] << " ";
	std::cout << "\n";
}

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
	dijkstra(1, n, next);
	__Made in France__
}
