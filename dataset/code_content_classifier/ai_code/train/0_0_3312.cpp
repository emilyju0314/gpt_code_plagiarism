#include <iostream>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, k;
        std::cin >> n >> k;

        if (n <= k) {
            std::cout << (k + n - 1) / n << std::endl;
        } else {
            std::cout << 2 << std::endl;
        }
    }

    return 0;
}