#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool isHalfPalindrome(const std::string& s) {
    int n = s.length();
    for (int i = 0; i < n; i += 2) {
        if (s[i] != s[n - i - 1]) {
            return false;
        }
    }
    return true;
}

std::vector<std::string> generateSubstrings(const std::string& s) {
    std::vector<std::string> substrings;

    for (int i = 0; i < s.length(); ++i) {
        for (int j = 1; j <= s.length() - i; ++j) {
            substrings.push_back(s.substr(i, j));
        }
    }

    return substrings;
}

int main() {
    std::string s;
    int k;

    std::cin >> s >> k;

    std::vector<std::string> substrings = generateSubstrings(s);
    std::sort(substrings.begin(), substrings.end());

    int count = 0;
    for (const std::string& sub : substrings) {
        if (isHalfPalindrome(sub)) {
            count++;
            if (count == k) {
                std::cout << sub << std::endl;
                break;
            }
        }
    }

    return 0;
}