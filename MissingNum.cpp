#include <iostream>
#include <vector>

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> v;
	v.reserve(n - 1);
	for (int i = 0; i < n - 1; i++)
	{
		int tmp;
		std::cin >> tmp;
		v.push_back(tmp);
	}
	int ans = 0;
	for (int i = 0; i < n - 1; i++)
	{
		ans ^= (i + 1);
		ans ^= v[i];
	}
	ans ^= n;

	std::cout << ans << std::endl;
	return 0;
}
