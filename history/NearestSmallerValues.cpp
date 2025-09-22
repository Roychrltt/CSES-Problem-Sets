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
	std::vector<int> v(n + 1);
	for (int i = 1; i <= n; i++)
		std::cin >> v[i];
	std::vector<int> ans(n + 1);
	std::stack<std::pair<int, int>> st;
	st.push({n, v[n]});
	for (int i = n - 1; i >= 1; i--)
	{
		if (v[i] > v[i + 1])
		{
			st.push({i, v[i]});
			continue;
		}
		while (!st.empty() && st.top().second > v[i])
		{
			ans[st.top().first] = i;
			st.pop();
		}
		st.push({i, v[i]});
	}
	std::copy(ans.begin() + 1, ans.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	__Made in France__
}
