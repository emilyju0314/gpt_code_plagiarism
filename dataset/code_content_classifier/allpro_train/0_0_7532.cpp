#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> permutation(n);

    for (int i = 0; i < n; i++) {
        std::cin >> permutation[i];
    }

    std::vector<int> prev_perm = permutation;
    std::vector<int> next_perm = permutation;

    if (std::prev_permutation(prev_perm.begin(), prev_perm.end())) {
        for (int i = 0; i < n; i++) {
            std::cout << prev_perm[i] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < n; i++) {
        std::cout << permutation[i] << " ";
    }
    std::cout << std::endl;

    if (std::next_permutation(next_perm.begin(), next_perm.end())) {
        for (int i = 0; i < n; i++) {
            std::cout << next_perm[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}