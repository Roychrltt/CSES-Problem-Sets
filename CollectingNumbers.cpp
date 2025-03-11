#include <bits/stdc++.h>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n;
	std::cin >> n;
	std::vector<int> v(n);
	std::vector<int> index(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> v[i];
		index[v[i] - 1] = i;
	}
	int count = 1;
	for (int i = 1; i < n; i++) {
		if (index[i] < index[i - 1])
			count++;
	}
	std::cout << count << std::endl;
	return 0;
}
