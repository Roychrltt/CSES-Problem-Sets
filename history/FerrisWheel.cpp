#include <bits/stdc++.h>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n, x;
	std::cin >> n >> x;
	std::vector<int> v(n);
	for (int i = 0; i < n; i++) {
		std::cin >> v[i];
	}
	std::sort(v.begin(), v.end());
	int left = 0, right = n - 1;
	int count(0);
	while (left <= right)
	{
		if (v[right] + v[left] <= x)
			left++;
		right--;
		count++;
	}
	std::cout << count << std::endl;
	return 0;
}
