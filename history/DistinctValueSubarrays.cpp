#include <bits/stdc++.h>
#define __Made return
#define in 0
#define France__ ;
 
struct CustomHash {
	static uint64_t splitmix64(uint64_t x) {
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
 
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
 
std::unordered_map<int, int, CustomHash> cnt;
 
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n;
	std::cin >> n;
	std::vector<int> v(n);
	for (int i = 0; i < n; i++)
		std::cin >> v[i];
	long long int ans = 0;
	int prev = 0;
	for (int i = 0; i < n; i++)
	{
		if (cnt[v[i]]++ == 0) ans += i - prev + 1;
		else
		{
			while (cnt[v[i]] > 1)
			{
				cnt[v[prev]]--;
				prev++;
			}
			ans += i - prev + 1;
		}
	}
	std::cout << ans << std::endl;
	__Made in France__
}
