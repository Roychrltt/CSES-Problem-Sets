#include <bits/stdc++.h>
#define __Made return
#define in 0
#define France__ ;

struct ranges
{
	int l, r, idx;
	bool operator<(const ranges& other) const
	{
		if (l == other.l) return r > other.r;
		return l < other.l;
	}
};

void solve(int n, const std::vector<std::pair<int, int>>& v, std::vector<std::vector<int>>& res)
{
	std::vector<ranges> range(n);
	for (int i = 0; i < n; i++)
	{
		range[i].l = v[i].first;
		range[i].r = v[i].second;
		range[i].idx = i;
	}
	std::sort(range.begin(), range.end());
	int minEnd = 2e9;
    for (int i = n - 1; i >= 0; i--) {
        if (range[i].r >= minEnd)
            res[0][range[i].idx] = 1;
        minEnd = std::min(minEnd, range[i].r);
    }

    int maxEnd = 0;
    for (int i = 0; i < n; i++) {
        if (range[i].r <= maxEnd)
            res[1][range[i].idx] = 1;
        maxEnd = std::max(maxEnd, range[i].r);
    }
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> v(n);
	for (int i = 0; i < n; i++)
		std::cin >> v[i].first >> v[i].second;
	std::vector<std::vector<int>> res(2, std::vector<int>(n));
	solve(n, v, res);
	std::copy(res[0].begin(), res[0].end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	std::copy(res[1].begin(), res[1].end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	__Made in France__
}
