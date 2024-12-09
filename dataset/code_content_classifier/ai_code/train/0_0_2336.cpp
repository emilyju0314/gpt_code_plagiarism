#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        std::cin >> weights[i];
    }

    std::vector<int> order(n);
    for (int i = 0; i < n; i++) {
        order[weights[i] - 1] = i;
    }

    int total_strength = 0;
    for (int i = 0; i < n - 1; i++) {
        total_strength += std::abs(order[i] - order[i + 1]);
    }

    std::cout << total_strength << std::endl;

    return 0;
}