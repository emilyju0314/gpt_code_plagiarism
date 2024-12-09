#include <iostream>

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m, k;
        std::cin >> n >> m >> k;

        if (m < n-1 || m > (n-1)*(n-2)/2) {
            std::cout << "NO" << std::endl;
        } else if (k <= 2) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}