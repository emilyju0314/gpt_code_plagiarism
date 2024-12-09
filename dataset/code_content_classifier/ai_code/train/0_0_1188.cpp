#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;

    int gcd = std::__gcd(a, b);

    if (gcd % 2 == 0) {
        std::cout << "Equal";
    } else if (a > b) {
        std::cout << "Masha";
    } else {
        std::cout << "Dasha";
    }

    return 0;
}