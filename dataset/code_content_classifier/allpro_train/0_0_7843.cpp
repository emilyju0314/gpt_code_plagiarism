#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> pairs(n);
    for (int i = 0; i < n; i++) {
        std::cin >> pairs[i].first >> pairs[i].second;
    }

    std::vector<int> food(2 * n + 1, 0);
    std::vector<std::pair<int, int>> result(n);

    for (int i = 0; i < n; i++) {
        result[i].first = 1 + (food[pairs[i].first] + food[pairs[i].second]) % 2;
        result[i].second = 3 - result[i].first;
        food[pairs[i].first] = result[i].first - 1;
        food[pairs[i].second] = result[i].second - 1;
    }

    for (int i = 0; i < n; i++) {
        std::cout << result[i].first << " " << result[i].second << "\n";
    }

    return 0;
}