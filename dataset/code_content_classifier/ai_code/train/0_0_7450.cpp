#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    // Check if a solution exists
    if (1 - 1.0/n <= 0.0) {
        std::cout << "NO" << std::endl;
        return 0;
    }

    std::vector<std::pair<int, int>> fractions;
    int remaining = n;

    // Find the sequence of fractions
    for (int i = 2; i <= n; ++i) {
        if (remaining - i <= n) {
            fractions.emplace_back(1, i);
            remaining -= i;
        }
    }

    // Output the result
    std::cout << "YES" << std::endl;
    std::cout << fractions.size() << std::endl;
    for (const auto& frac : fractions) {
        std::cout << frac.first << " " << frac.second << std::endl;
    }

    return 0;
}