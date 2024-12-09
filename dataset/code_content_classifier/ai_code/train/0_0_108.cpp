#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int k;
    std::cin >> k;

    std::string s;
    std::cin >> s;

    int n = s.length();

    std::sort(s.begin(), s.end());

    int freq[26] = {0};

    for (char c : s) {
        freq[c - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] % k != 0) {
            std::cout << "-1" << std::endl;
            return 0;
        }
    }

    std::string result = "";
    for (int i = 0; i < 26; i++) {
        result += std::string(freq[i]/k, 'a' + i);
    }

    for (int i = 0; i < k; i++) {
        std::cout << result;
    }

    std::cout << std::endl;

    return 0;
}