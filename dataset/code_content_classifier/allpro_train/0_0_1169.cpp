#include <iostream>
#include <cmath>

int main() {
    int x, y;
    std::cin >> x >> y;

    double distance = std::sqrt(x*x + y*y);

    if (std::abs(distance - std::round(distance)) < 1e-9) {
        std::cout << "black" << std::endl;
    } else {
        std::cout << "white" << std::endl;
    }

    return 0;
}