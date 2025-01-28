#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int main()
{
	std::vector<std::string> v(8);
	std::vector<int> col(8), diag1(15), diag2(15); 
	for (int i = 0; i < 8; i++)
	{
		std::cin >> v[i];	
	}
	int ans = 0;

	std::function<void(int)> dfs = [&](int r)
	{
		if (r == 8)
		{
			ans++;
			return;
		}
		for (int c = 0; c < 8; c++) {
			int rc = r - c + 7;
			if (v[r][c] == '*' || col[c] || diag1[r + c] || diag2[rc]) continue; 
			col[c] = diag1[r + c] = diag2[rc] = true;
			dfs(r + 1);
			col[c] = diag1[r + c] = diag2[rc] = false;
		}
	};
	dfs(0);

	std::cout << ans << std::endl;
	return 0;
}
