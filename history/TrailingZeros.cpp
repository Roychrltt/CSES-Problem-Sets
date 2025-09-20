#include <iostream>

int main(void)
{
	int n;
	std::cin >> n;

	int ans = 0;
	for (int i = 5; i <= n; i *= 5) {
		ans += n / i;
	}
	std::cout << ans << std::endl;
	return 0;
}
