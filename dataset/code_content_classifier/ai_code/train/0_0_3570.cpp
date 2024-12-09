#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool rhymeCheck(const std::string &line1, const std::string &line2, int k) {
    int vowels1 = 0, vowels2 = 0;
    for (int i = line1.size() - 1; i >= 0; i--) {
        if (line1[i] == 'a' || line1[i] == 'e' || line1[i] == 'i' || line1[i] == 'o' || line1[i] == 'u') {
            vowels1++;
            if (vowels1 == k) {
                break;
            }
        }
    }
    for (int i = line2.size() - 1; i >= 0; i--) {
        if (line2[i] == 'a' || line2[i] == 'e' || line2[i] == 'i' || line2[i] == 'o' || line2[i] == 'u') {
            vowels2++;
            if (vowels2 == k) {
                break;
            }
        }
    }
    if (vowels1 < k || vowels2 < k) {
        return false;
    }
    for (int i = 0; i < k; i++) {
        if (line1[line1.size() - 1 - i] != line2[line2.size() - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<std::string> lines(4 * n);
    for (int i = 0; i < 4 * n; i++) {
        std::cin >> lines[i];
    }

    std::vector<std::string> rhymeSchemes = {"aaaa", "aabb", "abab", "abba"};

    std::string rhymeScheme = "NO";
    for (const auto &rs : rhymeSchemes) {
        bool valid = true;
        for (int i = 0; i < n; i++) {
            std::vector<std::pair<int, int>> pairs = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}};
            bool pairwiseRhyme = true;
            for (const auto &pair : pairs) {
                if (!rhymeCheck(lines[i * 4 + pair.first], lines[i * 4 + pair.second], k)) {
                    pairwiseRhyme = false;
                    break;
                }
            }
            if (!pairwiseRhyme) {
                valid = false;
                break;
            }
        }
        if (valid) {
            rhymeScheme = rs;
            break;
        }
    }

    std::cout << rhymeScheme << std::endl;

    return 0;
}