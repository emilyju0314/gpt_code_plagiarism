#include <iostream>
#include <vector>

int main() {
    int n, b;
    std::cin >> n >> b;

    std::vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        std::cin >> prices[i];
    }

    int max_profit = b;
    for (int i = 0; i < n - 1; i++) {
        int num_dollars = b / prices[i];
        int remaining_money = b - num_dollars * prices[i];
        int total_money = num_dollars * prices[i + 1] + remaining_money;
        if (total_money > max_profit) {
            max_profit = total_money;
        }
    }

    std::cout << max_profit << std::endl;

    return 0;
}