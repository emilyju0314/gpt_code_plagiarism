#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int minErasedSymbols(std::string s) {
    std::vector<int> first(26, -1);
    std::vector<int> last(26, -1);

    for (int i = 0; i < s.length(); i++) {
        int c = s[i] - 'a';
        if (first[c] == -1) {
            first[c] = i;
        }
        last[c] = i;
    }

    int minErased = s.length();
    for (int i = 0; i < 26; i++) {
        if (first[i] == -1) continue;

        int curErased = 0;
        for (int j = 0; j < 26; j++) {
            if (first[j] == -1) continue;

            if (j == i) {
                curErased += last[j] - first[j] + 1;
            } else {
                curErased += last[j] - first[j] + 1;
            }
        }

        minErased = std::min(minErased, curErased);
    }

    if (minErased == s.length()) {
        return -1;
    } else {
        return minErased;
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;
        std::string s;
        std::cin >> s;

        int result = minErasedSymbols(s);
        std::cout << result << std::endl;
    }

    return 0;
}