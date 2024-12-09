#include <iostream>

int main() {
    int q;
    std::cin >> q;

    for (int i = 0; i < q; i++) {
        int l1, r1, l2, r2;
        std::cin >> l1 >> r1 >> l2 >> r2;

        // Choose any valid pair of integers within the segment ranges
        std::cout << l1 << " " << (l2 != l1 ? l2 : r2) << std::endl;
    }

    return 0;
}