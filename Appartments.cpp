#include <bits/stdc++.h>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector<int> people(n);
	std::vector<int> appart(m);
	for (int i = 0; i < n; i++) {
		std::cin >> people[i];
	}
	for (int i = 0; i < m; i++) {
		std::cin >> appart[i];
	}
	std::sort(people.begin(), people.end());
	std::sort(appart.begin(), appart.end());
	int ans(0), index(0);
	for (int i = 0; i < n; i++) {
		while (index < m && appart[index] < people[i] - k)
			index++;
		if (index == m) break;
		if (std::abs(appart[index] - people[i]) <= k)
		{
			ans++;
			index++;
		}
	}
	std::cout << ans << std::endl;
	return 0;
}
