#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> solutions(n);
    for (int i = 0; i < n; i++) {
        std::cin >> solutions[i].first >> solutions[i].second;
    }

    int prev_k = 0, prev_x = 0;
    for (int i = 0; i < n; i++) {
        int x = solutions[i].first;
        int k = solutions[i].second;
        if (x < prev_x || (x == prev_x && k <= prev_k)) {
            std::cout << "NO" << std::endl;
            return 0;
        }
        prev_x = x;
        prev_k = k;
    }

    std::cout << "YES" << std::endl;

    return 0;
}