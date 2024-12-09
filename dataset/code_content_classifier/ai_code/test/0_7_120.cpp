#include <iostream>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int l, r;
        std::cin >> l >> r;

        int diff = r - l + 1;
        int msb = 0;
        while ((1 << msb) <= diff) msb++;

        if ((1 << msb) - 1 == r) {
            std::cout << diff << std::endl;
        } else {
            std::cout << (1 << msb) - 1 - l << std::endl;
        }
    }

    return 0;
}