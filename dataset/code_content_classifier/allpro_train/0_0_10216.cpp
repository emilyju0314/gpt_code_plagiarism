#include <iostream>

int main() {
    int n;
    std::cin >> n;

    std::cout << n << std::endl;

    std::cout << "0 0" << std::endl;

    for (int i = 1; i <= n; ++i) {
        std::cout << i << " 0" << std::endl;
    }

    for (int i = 1; i <= n; ++i) {
        std::cout << i-1 << " " << i << std::endl;
    }

    return 0;
}