#include <iostream>
#include <string>

int main()
{
	std::string input;
	std::cin >> input;
	int len = input.length();
	int count = 1, ans = 1;
	char prev = input[0];
	for (int i = 1; i < len; i++)
	{
		if (input[i] == prev) count++;
		else
		{
			prev = input[i];
			count = 1;
		}
		ans = std::max(ans, count);
	}
	std::cout << ans << std::endl;
	return 0;
}
