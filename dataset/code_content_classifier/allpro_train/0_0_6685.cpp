#include <iostream>
#include <cmath>

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        std::cin >> n;

        if (n == 1) {
            std::cout << 9 << std::endl;
        } else {
            std::cout << 9;
            for (int j = 1; j < n; j++) {
                std::cout << (j+7)%10;
            }
            std::cout << std::endl;
        }
    }

    return 0;
}