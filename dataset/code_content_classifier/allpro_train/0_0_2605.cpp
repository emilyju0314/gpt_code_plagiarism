#include <iostream>
#include <vector>
#include <algorithm>

bool isPalindrome(const std::string &s) {
    for (int i = 0; i < s.length() / 2; i++) {
        if (s[i] != s[s.length() - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::string s;
        std::cin >> s;

        if (isPalindrome(s)) {
            std::cout << "-1\n";
        } else {
            std::sort(s.begin(), s.end());
            std::cout << s << std::endl;
        }
    }

    return 0;
}