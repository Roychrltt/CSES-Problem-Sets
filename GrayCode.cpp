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

/*  n = 1  n = 2  n = 3  n = 4
 *	  0		 0		00	  000	
 *			 1		01	  001
 *					11    011
 *					10	  010
 *						  110
 *						  111
 *						  101
 *						  100
 */
