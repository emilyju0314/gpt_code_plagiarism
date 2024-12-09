#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;

    while (true) {
        std::cin >> n >> m;

        if (n == 0 && m == 0) {
            break;
        }

        std::vector<std::vector<int>> scores(m, std::vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                std::cin >> scores[i][j];
            }
        }

        int highestTotal = 0;

        for (int j = 0; j < n; j++) {
            int totalScore = 0;
            for (int i = 0; i < m; i++) {
                totalScore += scores[i][j];
            }
            highestTotal = std::max(highestTotal, totalScore);
        }

        std::cout << highestTotal << std::endl;
    }

    return 0;
}