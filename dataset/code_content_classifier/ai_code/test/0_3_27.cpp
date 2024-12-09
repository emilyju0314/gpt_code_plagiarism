#include <iostream>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, m, k;
        std::cin >> n >> m >> k;

        if (n == 1 || m < n - 1 || m > (n * (n - 1)) / 2) {
            std::cout << "NO\n";
        } else if (k <= 1) {
            std::cout << "YES\n";
        } else if (k <= 1 + m / (n - 1)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }

    return 0;
}