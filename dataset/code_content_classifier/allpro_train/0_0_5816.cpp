#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> incomes(n);
    for (int i = 0; i < n; i++) {
        std::cin >> incomes[i];
    }

    int stable_income;
    std::cin >> stable_income;

    int k = -1;
    for (int i = 1; i <= n; i++) {
        bool profitable = true;
        for (int j = 0; j <= n - i; j++) {
            int total_income = 0;
            for (int l = j; l < j + i; l++) {
                total_income += incomes[l];
            }
            if (total_income + stable_income <= 0) {
                profitable = false;
                break;
            }
        }
        if (profitable) {
            k = i;
            break;
        }
    }

    std::cout << k << std::endl;

    return 0;
}