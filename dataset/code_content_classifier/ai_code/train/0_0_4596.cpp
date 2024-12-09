#include <iostream>

int main() {
    int n, k;
    std::cin >> n >> k;

    int sum = 0;
    for (int i = 1; i <= k; i++) {
        sum += i;
    }

    if (n < sum || n > 2 * sum) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl;

        int remaining = n - sum;
        for (int i = 1; i <= k - 1; i++) {
            std::cout << i << " ";
            remaining -= i;
        }

        std::cout << remaining + k << std::endl;
    }

    return 0;
}