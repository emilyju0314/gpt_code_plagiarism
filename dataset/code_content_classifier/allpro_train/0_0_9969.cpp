#include <iostream>

int main() {
    int a;
    std::cin >> a;

    if (a % 10 == 5 || a / 10 == 5) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}