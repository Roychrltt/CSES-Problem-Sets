#include <iostream>
#include <vector>
#include <iterator>

int main()
{
	int n;
	std::cin >> n;
	if (n < 3 || (n % 4 && (n + 1) % 4))
	{
		std::cout << "NO" << std::endl;
		return 0;
	}
	std::cout << "YES" << std::endl;
	std::vector<int> v1, v2;
	v1.reserve(n / 2 + 1);
	v2.reserve(n / 2 + 1);
	long long int cur = 0;
	long long int sum = (long long)n * (n + 1) / 4;
	if (n % 2)
	{
		v1.push_back(n);
		cur += n;
	}
	int left = 1;
	int right = n % 2 ? n - 1 : n;
	while (cur < sum)
	{
		cur += left + right;
		v1.push_back(left++);
		v1.push_back(right--);
	}
	while (left < right)
	{
		v2.push_back(left++);
		v2.push_back(right--);
	}
	std::cout << v1.size() << std::endl;
	std::copy(v1.begin(), v1.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	std::cout << v2.size() << std::endl;
	std::copy(v2.begin(), v2.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	return 0;
}
