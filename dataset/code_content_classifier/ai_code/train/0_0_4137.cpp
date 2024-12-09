#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;

    if (a + b == 15) {
        std::cout << "+";
    } else if (a * b == 15) {
        std::cout << "*";
    } else {
        std::cout << "x";
    }

    return 0;
}