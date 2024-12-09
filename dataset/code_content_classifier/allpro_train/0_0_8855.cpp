#include <iostream>
#include <string>
#include <algorithm>

bool is_alphabetical(std::string s) {
    std::string expected = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] < expected.front())
            expected = expected + s[i];
        else
            expected = s[i] + expected;
    }
    return s == expected;
}

int main() {
    int t;
    std::cin >> t;

    std::string s;

    for (int i = 0; i < t; i++) {
        std::cin >> s;
        if (is_alphabetical(s))
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;
    }

    return 0;
}