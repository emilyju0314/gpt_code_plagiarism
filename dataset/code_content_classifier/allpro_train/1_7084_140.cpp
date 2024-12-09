#include <iostream>

#define TSUBO 3.305785

int main()
{
	long double a, b;
	std::cin >> a >> b;
	
	std::cout << std::fixed << a*b / TSUBO << std::endl;
	
	return 0;
}

