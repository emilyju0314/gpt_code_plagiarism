#include <iostream>
#include <vector>
#include <string>

std::string getSuffix(const std::string& line, int k) {
    std::string suffix = "";
    int vowelCount = 0;
    
    for (int i = line.size() - 1; i >= 0; i--) {
        if (line[i] == 'a' || line[i] == 'e' || line[i] == 'i' || line[i] == 'o' || line[i] == 'u') {
            vowelCount++;
            if (vowelCount == k) {
                suffix = line.substr(i, line.size() - i);
                break;
            }
        }
    }
    
    return suffix;
}

std::string getRhymeScheme(int n, int k, const std::vector<std::string>& poem) {
    bool aabb = true;
    bool abab = true;
    bool abba = true;
    bool aaaa = true;

    for (int i = 0; i < n; i++) {
        std::string suffix_a = getSuffix(poem[i * 4], k);
        std::string suffix_b = getSuffix(poem[i * 4 + 1], k);
        std::string suffix_c = getSuffix(poem[i * 4 + 2], k);
        std::string suffix_d = getSuffix(poem[i * 4 + 3], k);

        if (suffix_a != suffix_b) {
            aabb = false;
        }
        if (i % 2 == 0) {
            if (suffix_a != suffix_c || suffix_b != suffix_d) {
                abab = false;
            }
        } else {
            if (suffix_a != suffix_d || suffix_b != suffix_c) {
                abab = false;
            }
        }
        if (suffix_a != suffix_d || suffix_b != suffix_c) {
            abba = false;
        }
        if (suffix_a != suffix_b || suffix_b != suffix_c || suffix_c != suffix_d) {
            aaaa = false;
        }
    }

    if (aaaa) {
        return "aaaa";
    }
    if (aabb) {
        return "aabb";
    }
    if (abab) {
        return "abab";
    }
    if (abba) {
        return "abba";
    }

    return "NO";
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<std::string> poem(4 * n);
    for (int i = 0; i < 4 * n; i++) {
        std::cin >> poem[i];
    }

    std::string rhymeScheme = getRhymeScheme(n, k, poem);
    std::cout << rhymeScheme << std::endl;

    return 0;
}