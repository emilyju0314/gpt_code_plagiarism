#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool isIrreducibleAnagram(const std::string& s) {
    int freq[26] = {0};
    for (char c : s) {
        freq[c - 'a']++;
    }
    int oddCount = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 == 1) {
            oddCount++;
        }
    }
    return oddCount <= 1;
}

int main() {
    std::string s;
    std::cin >> s;

    int q;
    std::cin >> q;

    for (int i = 0; i < q; i++) {
        int l, r;
        std::cin >> l >> r;
        std::string sub = s.substr(l-1, r-l+1);
        if (isIrreducibleAnagram(sub)) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }

    return 0;
}