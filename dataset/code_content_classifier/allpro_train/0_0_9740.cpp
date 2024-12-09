#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;

    if (a == b) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl;
        std::cout << "0 0" << std::endl;
        std::cout << a << " " << b << std::endl;
        if (a > b) {
            std::cout << a - b << " 0" << std::endl;
        } else {
            std::cout << "0 " << b - a << std::endl;
        }
    }

    return 0;
}