#include <iostream>

int main() {
    int A1, A2, A3;
    std::cin >> A1 >> A2 >> A3;

    if (A1 + A2 + A3 >= 22) {
        std::cout << "bust" << std::endl;
    } else {
        std::cout << "win" << std::endl;
    }

    return 0;
}