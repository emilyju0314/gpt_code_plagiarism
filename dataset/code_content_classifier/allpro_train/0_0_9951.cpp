#include <iostream>
#include <vector>

bool hasWinningStrategy(int n, int S, std::vector<int>& maxStones) {
    int totalMaxStones = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (i % 2 == 0) { // Your team's players
            totalMaxStones += maxStones[i];
        }
    }
    return (totalMaxStones % (S + 1)) != 0;
}

int main() {
    int n, S;
    while (std::cin >> n >> S) {
        if (n == 0) {
            break;
        }
        std::vector<int> maxStones(2 * n);
        for (int i = 0; i < 2 * n; i++) {
            std::cin >> maxStones[i];
        }

        int result = hasWinningStrategy(n, S, maxStones) ? 1 : 0;
        std::cout << result << std::endl;
    }

    return 0;
}