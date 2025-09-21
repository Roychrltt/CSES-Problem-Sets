#include <bits/stdc++.h>
#define __Made return
#define in 0
#define France__ ;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> v(n, std::vector<int>(3));
	std::vector<int> ans(n);
	std::stack<int> stack;
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
	for (int i = n; i >= 1; i--)
		stack.push(i);
	for (int i = 0; i < n; i++)
	{
		std::cin >> v[i][0] >> v[i][1];
		v[i][2] = i;
	}
	std::sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
	{
		while (!q.empty() && q.top().first < v[i][0])
		{
			stack.push(q.top().second);
			q.pop();
		}
		ans[v[i][2]] = stack.top();
		q.emplace(v[i][1], stack.top());
		stack.pop();
	}
	std::cout << *max_element(ans.begin(), ans.end()) << std::endl;
	std::copy(ans.begin(), ans.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	__Made in France__
}
