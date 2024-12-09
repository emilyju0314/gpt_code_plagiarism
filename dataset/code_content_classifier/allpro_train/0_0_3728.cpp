#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> coordinates(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        std::cin >> coordinates[i];
    }

    std::sort(coordinates.begin(), coordinates.end());

    int minArea = (coordinates[n - 1] - coordinates[0]) * (coordinates[2 * n - 1] - coordinates[n]);

    for (int i = 1; i < n; i++) {
        minArea = std::min(minArea, (coordinates[(2 * n) - 1] - coordinates[0]) * (coordinates[i + n - 1] - coordinates[i]));
    }

    std::cout << minArea << std::endl;

    return 0;
}