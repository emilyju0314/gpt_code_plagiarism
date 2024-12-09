#include <iostream>
#include <string>
#include <algorithm>

bool isPalindrome(const std::string& s) {
    int start = 0;
    int end = s.length() - 1;

    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

std::string longestPalindrome(const std::string& s) {
    std::string prefix = "";
    std::string suffix = "";
    
    for (int i = 0; i < s.length(); i++) {
        prefix += s[i];
        suffix = "";
        for (int j = s.length() - 1; j >= i; j--) {
            suffix = s[j] + suffix;
            if (isPalindrome(prefix + suffix)) {
                return prefix + suffix;
            }
        }
    }
    
    return s.substr(0, 1); // In case no palindrome is found
}

int main() {
    int t;
    std::cin >> t;
    std::cin.ignore(); // Ignore the newline character after reading t

    for (int i = 0; i < t; i++) {
        std::string s;
        std::getline(std::cin, s);

        std::string result = longestPalindrome(s);

        std::cout << result << std::endl;
    }

    return 0;
}