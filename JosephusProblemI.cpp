#include <bits/stdc++.h>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n;
	std::cin >> n;
	std::queue<int> q;
	for (int i = 0; i < n; i++) {
		q.push(i + 1);
	}

	bool ok = false;
	while (!q.empty())
	{
		int el = q.front();
		q.pop();
		if (ok)
			std::cout << el << std::endl;
		else
			q.push(el);

		ok = !ok;
	}
	return 0;
}
