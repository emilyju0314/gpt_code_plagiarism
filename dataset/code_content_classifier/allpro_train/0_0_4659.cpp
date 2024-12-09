#include <iostream>
#include <cmath>

int main() {
    int x, y;
    std::cin >> x >> y;

    int min_presses = std::abs(y - x);

    if (x < y) {
        if ((y - x) % 2 != 0) {
            min_presses += 2;
        }
    } else {
        if ((x - y) % 2 == 0) {
            min_presses += 2;
        }
    }

    std::cout << min_presses << std::endl;

    return 0;
}