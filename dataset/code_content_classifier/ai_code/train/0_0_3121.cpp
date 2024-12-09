#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

bool isBetween(const std::string& str, const std::string& a, const std::string& b) {
    return str >= a && str <= b;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int k;
        std::cin >> k;

        std::string s, a, b;
        std::cin >> s >> a >> b;

        bool found = false;
        std::string templateStr;

        std::vector<char> templateChars(k);
        for (int i = 0; i < k; i++) {
            templateChars[i] = 'a' + i;
        }

        do {
            std::string newStr = s;
            for (int i = 0; i < k; i++) {
                char oldChar = 'a' + i;
                char newChar = templateChars[i];
                for (char& c : newStr) {
                    if (c == oldChar) {
                        c = newChar;
                    }
                }
            }

            if (isBetween(newStr, a, b)) {
                found = true;
                templateStr = std::string(templateChars.begin(), templateChars.end());
                break;
            }
        } while (std::next_permutation(templateChars.begin(), templateChars.end()));

        if (found) {
            std::cout << "YES" << std::endl;
            std::cout << templateStr << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}