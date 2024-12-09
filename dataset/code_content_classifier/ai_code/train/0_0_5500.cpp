#include <iostream>
#include <cmath>

int main() {
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int steps = std::max(dx, dy);

    std::cout << steps << std::endl;

    return 0;
}