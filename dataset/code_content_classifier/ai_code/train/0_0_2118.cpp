#include <iostream>

int main() {
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    if (x1 == x2) {
        int diff = abs(y1 - y2);
        std::cout << x1 + diff << " " << y1 << " " << x2 + diff << " " << y2 << std::endl;
    } else if (y1 == y2) {
        int diff = abs(x1 - x2);
        std::cout << x1 << " " << y1 + diff << " " << x2 << " " << y2 + diff << std::endl;
    } else if (abs(x1 - x2) == abs(y1 - y2)) {
        std::cout << x1 << " " << y2 << " " << x2 << " " << y1 << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }

    return 0;
}