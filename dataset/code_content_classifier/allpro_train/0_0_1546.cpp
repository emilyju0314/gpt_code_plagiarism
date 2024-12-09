#include <iostream>
#include <cmath>

int main() {
    int d, t;
    double x = 0, y = 0;

    while (true) {
        std::cin >> d >> t;
        if (d == 0 && t == 0) {
            break;
        }
        x += d * cos(t * M_PI / 180);
        y += d * sin(t * M_PI / 180);
    }

    std::cout << static_cast<int>(round(x)) << std::endl;
    std::cout << static_cast<int>(round(y)) << std::endl;

    return 0;
}