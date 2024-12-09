#include <iostream>

int main() {
    int D;
    std::cin >> D;

    if (D == 25) {
        std::cout << "Christmas" << std::endl;
    } else if (D == 24) {
        std::cout << "Christmas Eve" << std::endl;
    } else if (D == 23) {
        std::cout << "Christmas Eve Eve" << std::endl;
    } else {
        std::cout << "Christmas Eve Eve Eve" << std::endl;
    }

    return 0;
}