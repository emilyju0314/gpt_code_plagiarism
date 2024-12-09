#include <iostream>

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        int l1, l2, l3;
        std::cin >> l1 >> l2 >> l3;

        if (l1 == l2 + l3 || l2 == l1 + l3 || l3 == l1 + l2) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}