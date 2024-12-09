#include <iostream>
#include <cmath>

int main() {
    int a, b, x1, y1, x2, y2;
    std::cin >> a >> b >> x1 >> y1 >> x2 >> y2;

    int dx = abs(x1 - x2);
    int dy = abs(y1 - y2);

    int badCells = 0;

    if ((x1 + y1) % (2 * a) == 0 && (x2 + y2) % (2 * a) == 0) {
        if (dx % a == 0 && dy % a == 0) {
            badCells = 1;
        } else if (dx % a == 0 || dy % a == 0) {
            badCells = 2;
        } else {
            badCells = 3;
        }
    } else if ((x1 - y1) % (2 * b) == 0 && (x2 - y2) % (2 * b) == 0) {
        if (dx % b == 0 && dy % b == 0) {
            badCells = 1;
        } else if (dx % b == 0 || dy % b == 0) {
            badCells = 2;
        } else {
            badCells = 3;
        }
    }

    std::cout << badCells << std::endl;

    return 0;
}