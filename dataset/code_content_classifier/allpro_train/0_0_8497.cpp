#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int q;
    std::cin >> q;

    for (int i = 0; i < q; ++i) {
        int n, k;
        std::cin >> n >> k;

        std::vector<int> prices(n);
        for (int j = 0; j < n; ++j) {
            std::cin >> prices[j];
        }

        int min_price = *std::min_element(prices.begin(), prices.end());
        int max_price = *std::max_element(prices.begin(), prices.end());

        if (max_price - k <= min_price + k) {
            std::cout << min_price + k << "\n";
        } else {
            std::cout << "-1\n";
        }
    }

    return 0;
}