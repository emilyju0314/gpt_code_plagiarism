#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> powers(n);
    for (int i = 0; i < n; i++) {
        std::cin >> powers[i];
    }

    int winnerPower = powers[0];
    int consecutiveWins = 0;

    for (int i = 1; i < n; i++) {
        if (powers[i] > winnerPower) {
            winnerPower = powers[i];
            consecutiveWins = 1;
        } else {
            consecutiveWins++;
        }

        if (consecutiveWins == k) {
            break;
        }
    }

    std::cout << winnerPower << std::endl;

    return 0;
}