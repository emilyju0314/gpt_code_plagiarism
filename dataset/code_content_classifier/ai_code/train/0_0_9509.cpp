#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    if (s.length() == 2) {
        std::cout << s;
    } else {
        std::reverse(s.begin(), s.end());
        std::cout << s;
    }

    return 0;
}