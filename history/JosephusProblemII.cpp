#include <bits/stdc++.h>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n, k;
	std::cin >> n >> k;
	std::queue<int> q;
	for (int i = 0; i < n; i++) {
		q.push(i + 1);
	}

	int count = 0;
	while (!q.empty())
	{
		int el = q.front();
		q.pop();
		if (count == k)
		{
			std::cout << el << " ";
			count = 0;
		}
		else
		{
			q.push(el);
			count++;
		}
	}
	return 0;
}
