#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int minErasedSymbols(std::string s) {
    int n = s.length();
    int low = 0, high = n - 1;
    int erasedCount = 0;

    while (low < high) {
        if (s[low] != s[high]) {
            erasedCount++;
        }
        low++;
        high--;
    }

    return erasedCount;
}

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        std::string s;

        std::cin >> n;
        std::cin >> s;

        std::vector<int> charCount(26, 0);
        for (char c : s) {
            charCount[c - 'a']++;
        }

        bool palindromePossible = false;
        for (int count : charCount) {
            if (count >= 2 || count % 2 == 1) {
                palindromePossible = true;
                break;
            }
        }

        if (!palindromePossible) {
            std::cout << "-1" << std::endl;
        } else {
            int minErased = minErasedSymbols(s);
            std::cout << minErased << std::endl;
        }
    }

    return 0;
}