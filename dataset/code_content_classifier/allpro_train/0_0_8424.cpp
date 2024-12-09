#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    for (int test = 0; test < t; ++test) {
        int n, q;
        std::cin >> n >> q;

        std::vector<int> strengths(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> strengths[i];
        }

        // Calculate the initial strength of the army
        int army_strength = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                army_strength += strengths[i];
            } else {
                army_strength -= strengths[i];
            }
        }

        // Print the initial strength
        std::cout << army_strength << std::endl;

        // Process each swap
        for (int i = 0; i < q; ++i) {
            int l, r;
            std::cin >> l >> r;

            // Swap the pokémon at indices l and r
            std::swap(strengths[l-1], strengths[r-1]);

            // Update the army strength after the swap
            army_strength = 0;
            for (int j = 0; j < n; ++j) {
                if (j % 2 == 0) {
                    army_strength += strengths[j];
                } else {
                    army_strength -= strengths[j];
                }
            }

            // Print the current army strength after the swap
            std::cout << army_strength << std::endl;
        }
    }

    return 0;
}