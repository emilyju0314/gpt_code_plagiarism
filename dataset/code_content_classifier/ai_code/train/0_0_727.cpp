#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> monsters(n);
    std::vector<int> specialCells(m);

    for (int i = 0; i < n; i++) {
        std::cin >> monsters[i];
    }

    for (int i = 0; i < m; i++) {
        std::cin >> specialCells[i];
    }

    std::sort(monsters.begin(), monsters.end());
    std::sort(specialCells.begin(), specialCells.end());

    int maxSpecialCells = 0;
    for (int i = 0; i < n; i++) {
        int leftDistance = std::lower_bound(specialCells.begin(), specialCells.end(), monsters[i]) - specialCells.begin();
        int rightDistance = std::upper_bound(specialCells.begin(), specialCells.end(), monsters[i]) - specialCells.begin();

        if (rightDistance < m) {
            maxSpecialCells = std::max(maxSpecialCells, rightDistance - leftDistance);
        } else {
            maxSpecialCells = std::max(maxSpecialCells, m - leftDistance);
        }
    }

    std::cout << maxSpecialCells << std::endl;

    return 0;
}