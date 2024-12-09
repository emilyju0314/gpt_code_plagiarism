#include <iostream>
#include <string>
#include <cmath>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::string keyboard, word;
        std::cin >> keyboard >> word;

        int pos[26];
        for (int i = 0; i < 26; i++) {
            pos[keyboard[i] - 'a'] = i;
        }

        int totalTime = 0;
        int prevKey = 0;
        for (char c : word) {
            totalTime += std::abs(pos[c - 'a'] - prevKey);
            prevKey = pos[c - 'a'];
        }

        std::cout << totalTime << std::endl;
    }

    return 0;
}