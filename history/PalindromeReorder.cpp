#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int main()
{
	std::string input;
	std::cin >> input;
	int n = input.length();
	std::vector<int> v(26);
	for (int i = 0; i < n; i++)
	{
		v[input[i] - 'A']++;
	}
	int count = 0;
	char mark = 0;
	for (int i = 0; i < 26; i++)
	{
		if (v[i] % 2)
		{
			count++;
			mark = 'A' + i;
		}
		if (count > n % 2)
		{
			std::cout << "NO SOLUTION" << std::endl;
			return 0;
		}
	}
	std::string ans;
	for (int i = 0; i < 26; i++)
	{
		if (i != mark - 'A')
			ans.append(v[i] / 2, 'A' + i);
	}
	if (mark > 0) ans.append(v[mark - 'A'], mark);
	for (int i = 25; i >= 0; i--)
	{
		if (i != mark - 'A')
			ans.append(v[i] / 2, 'A' + i);
	}

	std::cout << ans << std::endl;

	return 0;
}
