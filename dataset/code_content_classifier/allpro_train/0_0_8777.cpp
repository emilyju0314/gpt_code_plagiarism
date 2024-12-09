#include <iostream>

int main() {
    int x, y;
    std::cin >> x >> y;

    int x1, y1, x2, y2;

    if (x > 0 && y > 0) {
        x1 = 0;
        y1 = x + y;
        x2 = x + y;
        y2 = 0;
    } else if (x > 0 && y < 0) {
        x1 = 0;
        y1 = y - x;
        x2 = y - x;
        y2 = 0;
    } else if (x < 0 && y > 0) {
        x1 = 0;
        y1 = x - y;
        x2 = x - y;
        y2 = 0;
    } else {
        x1 = 0;
        y1 = x + y;
        x2 = x + y;
        y2 = 0;
    }

    std::cout << x1 << " " << y1 << " " << x2 << " " << y2 << std::endl;

    return 0;
}