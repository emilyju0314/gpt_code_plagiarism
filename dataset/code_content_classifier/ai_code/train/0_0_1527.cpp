#include <iostream>
#include <string>

bool isPalindrome(const std::string& s) {
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string s;
    std::cin >> s;

    int n = s.length();
    bool canBePalindrome = false;

    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) {
            canBePalindrome = true;
            break;
        }
    }

    if (canBePalindrome) {
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - i - 1]) {
                std::string temp = s;
                temp[i] = temp[n - i - 1];
                if (isPalindrome(temp)) {
                    std::cout << "YES" << std::endl;
                    return 0;
                }
                break;
            }
        }
    } else {
        if (n % 2 == 1) {
            std::cout << "YES" << std::endl;
            return 0;
        }
    }

    std::cout << "NO" << std::endl;

    return 0;
}