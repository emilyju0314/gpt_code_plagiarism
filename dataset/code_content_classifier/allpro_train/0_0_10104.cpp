#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::vector<int> b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    std::map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    std::vector<char> oddFreqLetters;
    for (auto it : freq) {
        if (it.second % 2 != 0) {
            oddFreqLetters.push_back(it.first);
        }
    }

    std::sort(b.begin(), b.end(), std::greater<int>());

    int maxBeauty = 0;
    for (int i = 0; i < oddFreqLetters.size(); i++) {
        maxBeauty += b[i];
    }

    std::cout << maxBeauty << std::endl;

    return 0;
}