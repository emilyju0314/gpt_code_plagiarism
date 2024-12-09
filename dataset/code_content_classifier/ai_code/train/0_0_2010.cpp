#include <iostream>
#include <cmath>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        int sum1 = 0, sum2 = 0;
        for (int i = 1; i <= n/2; i++) {
            sum1 += std::pow(2, i);
        }

        for (int i = n/2 + 1; i <= n; i++) {
            sum2 += std::pow(2, i);
        }

        std::cout << std::abs(sum1 - sum2) << std::endl;
    }

    return 0;
}