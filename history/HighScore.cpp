#include <bits/stdc++.h>
using ll = long long;

std::vector<ll> vis(2501, 0);

void dfs(ll u, std::vector<std::vector<ll>> &adjrev, std::vector<ll> &reachable) {
	if (vis[u]) return;
	vis[u] = 1;
	reachable.push_back(u);
	for (auto &v : adjrev[u]) dfs(v, adjrev, reachable);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	ll n, m;
	std::cin >> n >> m;
	std::vector<std::vector<std::pair<ll,ll>>> adj(n + 1);
	std::vector<std::pair<std::pair<ll,ll>, ll>> edges;
	for (ll i = 0; i < m; i++) {
		ll u, v, w;
		std::cin >> u >> v >> w;
		edges.push_back({{u, v}, -w});
		adj[u].push_back({v, -w});
	}
	std::vector<ll> dist(n + 1, LLONG_MAX);
	dist[1] = 0;
	for (ll i = 1; i <= n; i++) {
		for (auto &e : edges) {
			ll u = e.first.first, v = e.first.second, w = e.second;
			if (dist[u] != LLONG_MAX) dist[v] = std::min(dist[v], dist[u] + w);
		}
	}
	std::set<ll> changed;
	for (auto &e : edges) {
		ll u = e.first.first, v = e.first.second, w = e.second;
		if (dist[u] != LLONG_MAX) {
			ll old = dist[v];
			dist[v] = std::min(dist[v], dist[u] + w);
			if (old != dist[v]) changed.insert(v);
		}
	}
	for (auto &e : edges) std::swap(e.first.first, e.first.second);
	std::vector<std::vector<ll>> adjrev(n + 1);
	for (auto &e : edges) adjrev[e.first.first].push_back(e.first.second);
	std::vector<ll> reachable;
	dfs(n, adjrev, reachable);
	bool ok = true;
	for (auto &x : reachable) if (changed.count(x)) { ok = false; break; }
	if (ok) std::cout << -dist[n] << "\n";
	else std::cout << "-1\n";
}

