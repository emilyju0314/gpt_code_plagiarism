#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;

    int product = a * b;

    if (product % 2 == 0) {
        std::cout << "Even" << std::endl;
    } else {
        std::cout << "Odd" << std::endl;
    }

    return 0;
}