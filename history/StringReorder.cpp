#include <bits/stdc++.h>
#define __Made return
#define in 0
#define France__ ;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	std::string s;
	std::cin >> s;
	int n = s.size();
	std::vector<int> cnt(26, 0);
	for (char c : s) cnt[c - 'A']++;
	for (int c : cnt) if (c > (n + 1) / 2)
	{
		std::cout << -1;
		return 0;
	}
	std::string ans;
	ans.reserve(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (cnt[j] == 0) continue;
			if (!ans.empty() && ans.back() == 'A' + j) continue;
			cnt[j]--;
			bool ok = true;
			int rem = n - i - 1;
			for (int k = 0; k < 26; k++)
			{
				if (cnt[k] > (rem + 1) / 2)
				{
					ok = false;
					break;
				}
			}
			if (ok)
			{
				ans.push_back('A' + j);
				break;
			}
			cnt[j]++;
		}
	}
	std::cout << ans;
	__Made in France__
}
