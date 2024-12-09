#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    if (a < b && a < c) {
        std::cout << "A" << std::endl;
    } else if (b < a && b < c) {
        std::cout << "B" << std::endl;
    } else {
        std::cout << "C" << std::endl;
    }

    return 0;
}