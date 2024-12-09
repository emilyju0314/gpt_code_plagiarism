#include <iostream>
#include <string>

int main() {
    int a1, a2, a3, a4;
    std::cin >> a1 >> a2 >> a3 >> a4;

    if (a3 > a4 || a1 > a2 + 1 || a2 > a1 + 1) {
        std::cout << -1 << std::endl;
        return 0;
    }

    if (a1 == a2) {
        for (int i = 0; i < a1; i++) {
            std::cout << "47";
        }
    } else if (a1 > a2) {
        std::cout << "4";
        for (int i = 0; i < a2; i++) {
            std::cout << "74";
        }
        for (int i = 0; i < a1 - a2; i++) {
            std::cout << "4";
        }
    } else {
        for (int i = 0; i < a1; i++) {
            std::cout << "47";
        }
        for (int i = 0; i < a2 - a1; i++) {
            std::cout << "7";
        }
    }

    std::cout << std::endl;

    return 0;
}