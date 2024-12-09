#include <iostream>

int main() {
    int r, g, b;
    std::cin >> r >> g >> b;

    int num = 100 * r + 10 * g + b;

    if(num % 4 == 0) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}