#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> charges(n);
    
    for (int i = 0; i < n; i++) {
        std::cin >> charges[i];
    }

    int bonus = 0;
    long long total_cost = 0;

    for (int i = 0; i < n; i++) {
        if (bonus >= charges[i]) {
            bonus -= charges[i];
        } else {
            int cash_to_pay = charges[i] - bonus;
            bonus = 0;
            total_cost += cash_to_pay;
            bonus += cash_to_pay / 10;
        }
    }

    std::cout << total_cost << std::endl;

    return 0;
}