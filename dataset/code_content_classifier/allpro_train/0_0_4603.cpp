#include <iostream>
#include <unordered_map>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::unordered_map<std::string, int> prices;
    for (int i = 0; i < n; i++) {
        int price;
        std::cin >> price;
        prices[std::to_string(price)] = price;
    }

    int min_sum = 0, max_sum = 0;
    for (int i = 0; i < m; i++) {
        std::string fruit;
        std::cin >> fruit;
        min_sum += prices[std::to_string(prices.begin()->second)];
        max_sum += prices[std::to_string(prices.rbegin()->second)];
    }

    std::cout << min_sum << " " << max_sum << std::endl;

    return 0;
}