#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> strengths(n);
    for (int i = 0; i < n; i++) {
        std::cin >> strengths[i];
    }

    int piles = 0;
    int currentStrength = 0;

    for (int i = 0; i < n; i++) {
        currentStrength = std::max(currentStrength, strengths[i]);
        if (currentStrength == i) {
            piles++;
            currentStrength = 0;
        }
    }

    std::cout << piles << std::endl;

    return 0;
}