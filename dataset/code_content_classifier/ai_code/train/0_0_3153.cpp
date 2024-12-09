#include <iostream>

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == n / 2 && j == n / 2) {
                std::cout << "D";
            } else if (i + j >= n / 2 && i + n / 2 >= j && j + n / 2 >= i && i <= n / 2) {
                std::cout << "D";
            } else {
                std::cout << "*";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}