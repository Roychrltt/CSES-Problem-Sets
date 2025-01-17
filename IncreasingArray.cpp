#include <iostream>
#include <vector>

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> v;
	v.reserve(n);
	for (int i = 0; i < n; i++)
	{
		int tmp;
		std::cin >> tmp;
		v.push_back(tmp);
	}
	long long int ans = 0;
	for (int i = 1; i < n; i++)
	{
		if (v[i] < v[i - 1])
		{
			ans += static_cast<long long>(v[i - 1]) - v[i];
			v[i] = v[i - 1];
		}
	}

	std::cout << ans << std::endl;
	return 0;
}
