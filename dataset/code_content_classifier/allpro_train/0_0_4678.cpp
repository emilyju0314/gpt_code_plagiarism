#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> foodTypes(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> foodTypes[i];
    }

    std::unordered_map<int, int> foodCounts;
    for (int i = 0; i < m; ++i) {
        foodCounts[foodTypes[i]]++;
    }

    int minFoodCount = INT_MAX;
    for (auto it = foodCounts.begin(); it != foodCounts.end(); ++it) {
        if (it->second < minFoodCount) {
            minFoodCount = it->second;
        }
    }

    if (minFoodCount >= n) {
        std::cout << n << std::endl;
    } else {
        std::cout << minFoodCount << std::endl;
    }

    return 0;
}