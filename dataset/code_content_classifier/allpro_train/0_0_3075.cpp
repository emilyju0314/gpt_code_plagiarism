#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> balances(n);
    for (int i = 0; i < n; i++) {
        std::cin >> balances[i];
    }

    int operations = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += balances[i];
        if (sum != 0) {
            operations++;
        }
    }

    std::cout << operations << std::endl;

    return 0;
}