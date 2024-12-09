#include <iostream>
#include <string>
#include <algorithm>

int main()
{
	std::string s;
	std::cin >> s;

	size_t cg = std::count(s.begin(), s.end(), 'g');
	size_t cp = s.length() - cg;

	std::cout << (cp + cg) / 2 - cp << std::endl;

	return 0;
}
