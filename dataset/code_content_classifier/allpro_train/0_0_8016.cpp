#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<std::string> permutations;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (j == i) continue;
            for (int k = 0; k < 10; ++k) {
                if (k == i || k == j) continue;
                for (int l = 0; l < 10; ++l) {
                    if (l == i || l == j || l == k) continue;
                    permutations.push_back(std::to_string(i) + std::to_string(j) + std::to_string(k) + std::to_string(l));
                }
            }
        }
    }

    std::random_shuffle(permutations.begin(), permutations.end());

    for (const auto& perm : permutations) {
        std::cout << perm << std::endl;
        std::cout.flush();

        int bulls, cows;
        std::cin >> bulls >> cows;

        if (bulls == 4 && cows == 0) {
            break;
        }
    }

    return 0;
}