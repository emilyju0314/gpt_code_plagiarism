#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> towerHeights(n);
    for(int i = 0; i < n; i++) {
        std::cin >> towerHeights[i];
    }

    std::sort(towerHeights.begin(), towerHeights.end(), std::greater<int>());

    int maxHeight = towerHeights[0];
    int totalCost = 0;

    for(int i = 1; i < n; i++) {
        int diff = maxHeight - towerHeights[i];
        totalCost += diff;
        if(totalCost > k) {
            std::cout << i << std::endl;
            return 0;
        }
    }

    std::cout << n << std::endl;

    return 0;
}