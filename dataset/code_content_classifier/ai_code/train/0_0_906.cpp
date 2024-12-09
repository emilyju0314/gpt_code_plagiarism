#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> costs(n);
    for (int i = 0; i < n; i++) {
        std::cin >> costs[i];
    }

    std::sort(costs.begin(), costs.end());

    for (int i = 0; i < n; i++) {
        std::cout << costs[i] << " ";
    }

    return 0;
}