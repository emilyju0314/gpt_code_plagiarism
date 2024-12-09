#include <iostream>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int l, r;
        std::cin >> l >> r;

        int x = r;
        while ((x & (x - 1)) == 0 && x >= l) {
            x >>= 1;
        }

        std::cout << (x - 1 - l) + std::max(0, l - (x >> 1)) << std::endl;
    }

    return 0;
}