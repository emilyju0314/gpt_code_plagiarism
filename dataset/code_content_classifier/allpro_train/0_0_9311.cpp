#include <iostream>
#include <cmath>

int main() {
    int a, b;
    std::cin >> a >> b;

    if (a < b) {
        std::cout << "-1" << std::endl;
    } else {
        double x = (a + b) / (2.0 * floor((a + b) / (2.0 * b)));
        std::cout << x << std::endl;
    }

    return 0;
}