#include <iostream>
#include <cmath>

int main() {
    long long x;
    std::cin >> x;

    x = std::abs(x) % 360; // Get the positive remainder of x when divided by 360

    if (x == 0 || x == 90 || x == 180 || x == 270) {
        std::cout << 1; // If x is a multiple of 90, only one turn is needed
    } else if (x == 30 || x == 150 || x == 210 || x == 330) {
        std::cout << 3; // If x is 30, 150, 210, or 330, three turns are needed for minimum deviation
    } else {
        std::cout << 2; // For any other angle, two turns are needed for minimum deviation
    }

    return 0;
}