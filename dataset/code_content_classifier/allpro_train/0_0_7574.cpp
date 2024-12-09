#include <iostream>
#include <string>

bool isPalindrome(const std::string& s) {
    int i = 0, j = s.length() - 1;
    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main() {
    std::string s;
    int k;

    std::cin >> s >> k;

    if (s.length() % k != 0) {
        std::cout << "NO" << std::endl;
        return 0;
    }

    int len = s.length() / k;
    for (int i = 0; i < k; i++) {
        std::string substr = s.substr(i * len, len);
        if (!isPalindrome(substr)) {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }

    std::cout << "YES" << std::endl;

    return 0;
}