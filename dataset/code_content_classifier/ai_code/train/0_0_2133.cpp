#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, w;
    std::cin >> n >> w;

    std::vector<int> cups(n);
    int total_needed = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> cups[i];
        total_needed += (cups[i] + 1) / 2;
    }

    if (total_needed > w) {
        std::cout << -1 << std::endl;
        return 0;
    }

    std::vector<std::pair<int, int>> sorted_cups;
    for (int i = 0; i < n; i++) {
        sorted_cups.push_back({(cups[i] + 1) / 2, i});
    }

    std::sort(sorted_cups.begin(), sorted_cups.end(), std::greater<std::pair<int, int>>());

    for (int i = 0; i < n; i++) {
        int index = sorted_cups[i].second;
        int to_fill = std::min(cups[index], w - total_needed + sorted_cups[i].first);
        total_needed += to_fill;

        std::cout << to_fill << " ";
    }
    std::cout << std::endl;

    return 0;
}