#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <iterator>


int main()
{
	std::string input;
	std::cin >> input;
	int len = input.length();
	std::unordered_map<char, int> map;
	for (char c : input)
		map[c]++;
	std::vector<std::string> v;
	std::string current;
	std::function<void(std::string&)> dfs = [&](std::string& current) -> void
	{
		if (current.length() == len)
		{
			v.push_back(current);
			return;
		}
		for (auto &[a, b] : map)
		{
			if (b > 0)
			{
				current += a;
				map[a]--;
				dfs(current);
				map[a]++;
				current.pop_back();
			}
		}
	};
	dfs(current);
	int size = v.size();
	std::cout << size << std::endl;
	std::sort(v.begin(), v.end());
	std::copy(v.begin(), v.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
	return 0;
}
