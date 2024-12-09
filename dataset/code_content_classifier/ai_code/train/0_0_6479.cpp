#include <iostream>

int main() {
    int b1, b2, b3;
    std::cin >> b1 >> b2 >> b3;

    if (b1 == 1 && b2 == 1 && b3 == 0) {
        std::cout << "Open" << std::endl;
    } else if (b1 == 0 && b2 == 0 && b3 == 1) {
        std::cout << "Open" << std::endl;
    } else {
        std::cout << "Close" << std::endl;
    }

    return 0;
}