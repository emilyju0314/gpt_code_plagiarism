#include <iostream>

int main() {
    long long a, b, c;
    std::cin >> a >> b >> c;

    if (c == 0) {
        if (a == b) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    } else if ((b - a) % c == 0 && (b - a) / c >= 0) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}