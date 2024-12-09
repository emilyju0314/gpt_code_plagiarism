#include <iostream>
#include <cmath>

int main() {
    int a;
    std::cin >> a;

    if (a == 0) {
        std::cout << 1 << std::endl;
    } else {
        std::cout << static_cast<int>(std::pow(2, a)) << std::endl;
    }

    return 0;
}