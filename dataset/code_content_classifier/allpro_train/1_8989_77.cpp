#include <iostream>
#include <string>

int main() {
	std::string s;
	int k;

	std::cin >> s >> k;
	for (size_t i = 0; i < s.size() && k > 0; ++i) {
		if (s[i] != 'a' && k >= 'z' - s[i] + 1) {
			k -= 'z' - s[i] + 1;
			s[i] = 'a';
		}

		if (i == s.size() - 1)
			s[i] = 'a' + (s[i] - 'a' + k) % ('z' - 'a' + 1);
	}

	std::cout << s << std::endl;
}