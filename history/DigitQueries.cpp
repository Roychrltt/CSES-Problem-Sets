#include <iostream>

static void solve(long long num)
{
	long long length = 1;  
    long long count = 9;   
    long long start = 1;   

    
    while (num > length * count) {
        num -= length * count;  
        length++;             
        count *= 10;          
        start *= 10;          
    }

    
    long long cur = start + (num - 1) / length;  
    std::string s = std::to_string(cur);           
    std::cout << s[(num - 1) % length] - '0' << std::endl;
}

int main(void)
{
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		long long num;
		std::cin >> num;
		solve(num);
	}
	return 0;
}
