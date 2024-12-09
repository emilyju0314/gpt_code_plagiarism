#include <iostream>
#include <vector>
#include <algorithm>

bool isPalindrome(std::string str) {
    std::string cleanStr;
    for (char c : str) {
        if (isalpha(c)) {
            cleanStr.push_back(std::toupper(c));
        }
    }
    return std::equal(cleanStr.begin(), cleanStr.begin() + cleanStr.size() / 2, cleanStr.rbegin());
}

int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        std::string palindromeStr;
        bool foundPalindrome = false;

        for (int i = 0; i < line.size(); i++) {
            for (int j = 2; j <= line.size() - i; j++) {
                std::string sub = line.substr(i, j);
                
                if (isPalindrome(sub) && sub.size() > 2) {
                    if (palindromeStr.find(sub) == std::string::npos) {
                        if (foundPalindrome) {
                            palindromeStr += " ";
                        }
                        palindromeStr += sub;
                        foundPalindrome = true;
                    }
                }
            }
        }

        if (palindromeStr.size() > 0) {
            std::cout << palindromeStr << std::endl;
        } else {
            std::cout << std::endl;
        }
    }

    return 0;
}