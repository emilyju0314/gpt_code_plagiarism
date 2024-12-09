#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> prices;

    for (int i = 0; i < n; i++) {
        int price;
        std::cin >> price;
        prices.push_back(price);
    }

    int maxPrice = *std::max_element(prices.begin(), prices.end());
    int winnerIndex = std::find(prices.begin(), prices.end(), maxPrice) - prices.begin();

    prices.erase(prices.begin() + winnerIndex);

    int secondMaxPrice = *std::max_element(prices.begin(), prices.end());

    std::cout << winnerIndex + 1 << " " << secondMaxPrice << std::endl;

    return 0;
}