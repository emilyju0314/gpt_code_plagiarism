#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> table(101, std::vector<int>(101, 0)); // Initialize table with 0 values

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;

        for (int x = x1; x <= x2; x++) {
            for (int y = y1; y <= y2; y++) {
                table[x][y]++;
            }
        }
    }

    int sum = 0;
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            sum += table[i][j];
        }
    }

    std::cout << sum << std::endl;

    return 0;
}