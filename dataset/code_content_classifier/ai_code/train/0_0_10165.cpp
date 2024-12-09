#include <iostream>
#include <cmath>

int main() {
    int x, y;
    std::cin >> x >> y;

    if (x == 0 && y == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    int maxCoord = std::max(abs(x), abs(y));
    int steps = 2 * maxCoord - 1;

    if (y == maxCoord) {
        steps += x > 0 ? 1 : 3;
    } else {
        steps += y > 0 ? (x > 0 ? 0 : 2) : (x > 0 ? 2 : 0);
    }

    std::cout << steps << std::endl;

    return 0;
}