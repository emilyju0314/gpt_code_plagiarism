#include <iostream>
#include <cmath>

int main() {
    int x, y;
    std::cin >> x >> y;

    double result1 = y * std::log(x);
    double result2 = x * std::log(y);

    if (result1 < result2) {
        std::cout << "<";
    } else if (result1 > result2) {
        std::cout << ">";
    } else {
        std::cout << "=";
    }

    return 0;
}