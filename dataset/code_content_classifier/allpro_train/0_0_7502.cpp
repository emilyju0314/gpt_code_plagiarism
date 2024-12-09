#include <iostream>

int main() {
    int x, y;
    std::cin >> x >> y;

    if (x == 0 && y == 1) {
        std::cout << "Yes" << std::endl;
    } else if (x >= y - 1 && (x - y + 1) % 2 == 0) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}