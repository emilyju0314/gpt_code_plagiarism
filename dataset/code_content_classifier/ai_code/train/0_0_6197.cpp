#include <iostream>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    if (n % 2 == 0) {
        std::cout << "Marsel" << std::endl;
    } else {
        if ((n * m - 1) % (2 * k) == 0) {
            std::cout << "Marsel" << std::endl;
        } else {
            std::cout << "Timur" << std::endl;
        }
    }

    return 0;
}