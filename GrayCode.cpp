#include <iostream>
#include <vector>
#include <bitset>

int main()
{
	int n;
	std::cin >> n;
	int total = 1 << n;
    for (int i = 0; i < total; i++)
	{
        int gray = i ^ (i >> 1); 
		std::cout << std::bitset<16>(gray).to_string().substr(16 - n) << std::endl; 
    }
	return 0;
}
