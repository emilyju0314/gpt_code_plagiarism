#include <iostream>
#include <vector>
#include <unordered_set>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> words(n, std::vector<int>());
    std::vector<std::unordered_set<int>> letters(m + 1);

    for (int i = 0; i < n; i++) {
        int len;
        std::cin >> len;
        for (int j = 0; j < len; j++) {
            int letter;
            std::cin >> letter;
            words[i].push_back(letter);
            if (letter <= m) {
                letters[letter].insert(i);
            }
        }
    }

    std::vector<int> large_letters;
    
    for (int i = 1; i <= m; i++) {
        bool small_before_large = false;
        for (int j = i + 1; j <= m; j++) {
            if (!letters[i].empty() && !letters[j].empty()) {
                auto it_i = letters[i].begin();
                auto it_j = letters[j].begin();
                if (*it_i < *it_j) {
                    small_before_large = true;
                    break;
                }
            }
        }
        if (small_before_large) {
            large_letters.push_back(i);
        }
    }

    if (large_letters.empty()) {
        std::cout << "No" << std::endl;
    } else {
        std::cout << "Yes" << std::endl;
        std::cout << large_letters.size() << std::endl;
        for (int letter : large_letters) {
            std::cout << letter << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}