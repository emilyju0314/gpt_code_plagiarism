#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> currency(n);
    for (int i = 0; i < n; i++) {
        std::cin >> currency[i];
    }

    int max_profit = -1;
    int min_currency = currency[0];

    for (int i = 1; i < n; i++) {
        int profit = currency[i] - min_currency;
        if (profit > max_profit) {
            max_profit = profit;
        }

        if (currency[i] < min_currency) {
            min_currency = currency[i];
        }
    }

    std::cout << max_profit << std::endl;

    return 0;
}