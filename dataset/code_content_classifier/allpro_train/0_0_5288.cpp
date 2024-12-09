#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> sticks(n);
    for (int i = 0; i < n; i++) {
        std::cin >> sticks[i];
    }

    int minimum_cost = INT_MAX;
    int best_t = 0;

    for (int t = 1; t <= 100; t++) {
        int total_cost = 0;
        for (int i = 0; i < n; i++) {
            total_cost += std::abs(sticks[i] - t - 1) + std::abs(t - sticks[i]);
        }

        if (total_cost < minimum_cost) {
            minimum_cost = total_cost;
            best_t = t;
        }
    }

    std::cout << best_t << " " << minimum_cost << std::endl;

    return 0;
}