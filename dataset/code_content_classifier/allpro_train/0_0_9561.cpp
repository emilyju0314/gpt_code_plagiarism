#include <iostream>
#include <vector>
#include <set>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::set<int>> languages(n);

    for (int i = 0; i < n; ++i) {
        int k;
        std::cin >> k;
        for (int j = 0; j < k; ++j) {
            int lang;
            std::cin >> lang;
            languages[i].insert(lang);
        }
    }

    int min_amount = m;

    for (int i = 0; i < n; ++i) {
        std::set<int> learned_languages;
        for (const auto &s : languages) {
            if (i != &s - &languages[0]) {
                for (int lang : s) {
                    learned_languages.insert(lang);
                }
            }
        }

        int diff = m - learned_languages.size();
        if (diff < min_amount) {
            min_amount = diff;
        }
    }

    std::cout << min_amount << std::endl;

    return 0;
}