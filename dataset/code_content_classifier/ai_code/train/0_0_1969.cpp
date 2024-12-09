#include <iostream>

int main() {
    int X;
    std::cin >> X;

    // Check if it is possible to buy some set of items that cost exactly X yen in total
    if (X % 100 >= 0 && X % 100 <= 5 && X / 100 <= 10000) {
        std::cout << 1 << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }

    return 0;
}