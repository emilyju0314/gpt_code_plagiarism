#include <iostream>
#include <cmath>

int main() {
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    int x, y;
    std::cin >> x >> y;

    if ((std::abs(x2 - x1) % x == 0) && (std::abs(y2 - y1) % y == 0) && ((std::abs(x2 - x1) / x) % 2 == (std::abs(y2 - y1) / y) % 2)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}