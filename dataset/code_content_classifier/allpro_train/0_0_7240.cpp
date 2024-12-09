#include <iostream>

int main() {
    int l, r, x, y, k;
    std::cin >> l >> r >> x >> y >> k;

    bool found = false;
    for (int exp = l; exp <= r; ++exp) {
        for (int cost = x; cost <= y; ++cost) {
            if (static_cast<double>(exp) / cost == k) {
                found = true;
                break;
            }
        }
    }

    if (found) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}