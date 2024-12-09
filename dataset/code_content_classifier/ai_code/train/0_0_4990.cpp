#include <iostream>
#include <cmath>

int main() {
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    int dx = std::abs(x1 - x2);
    int dy = std::abs(y1 - y2);

    std::cout << 2 * (dx + dy) + 4 << std::endl;

    return 0;
}