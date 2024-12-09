#include <iostream>

int main() {
    int n;
    std::cin >> n;

    if (n % 2 == 0) {
        std::cout << "-1" << std::endl;
    } else {
        for (int i = 0; i < n; i++) {
            std::cout << i << " ";
        }
        std::cout << std::endl;

        for (int i = 0; i < n; i++) {
            std::cout << i << " ";
        }
        std::cout << std::endl;

        for (int i = 0; i < n; i++) {
            std::cout << (i + i) % n << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}