#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n, x;
    std::cin >> n >> x;

    std::vector<int> foundCards(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> foundCards[i];
        sum += foundCards[i];
    }

    int cardsNeeded = ceil(abs(sum) / (double)x);
    std::cout << cardsNeeded << std::endl;

    return 0;
}