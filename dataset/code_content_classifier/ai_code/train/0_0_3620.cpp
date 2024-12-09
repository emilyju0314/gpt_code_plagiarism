#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    int n = s.length();
    if (n > 2) {
        std::cout << s[0] << n - 2 << s[n-1] << std::endl;
    } else {
        std::cout << s << std::endl;
    }

    return 0;
}