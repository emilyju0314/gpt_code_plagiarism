#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

int main() {
    std::string s;
    std::cin >> s;

    int k;
    std::cin >> k;

    std::unordered_map<char, int> charCount;
    for (char c : s) {
        charCount[c]++;
    }

    std::vector<std::pair<int, char>> charCounts;
    for (auto p : charCount) {
        charCounts.push_back({p.second, p.first});
    }

    std::sort(charCounts.begin(), charCounts.end());

    int numCharsLeft = 0;
    std::string newString = "";
    for (auto p : charCounts) {
        if (p.first <= k) {
            numCharsLeft++;
            k -= p.first;
            newString += std::string(p.first, p.second);
        } else {
            break;
        }
    }

    std::cout << numCharsLeft << std::endl;
    std::cout << newString << std::endl;

    return 0;
}