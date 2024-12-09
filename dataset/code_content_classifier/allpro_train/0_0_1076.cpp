#include <iostream>
#include <cmath>

int main() {
    long long x, y, m;
    std::cin >> x >> y >> m;

    if (x >= m || y >= m) {
        std::cout << 0 << std::endl;
        return 0;
    }

    if (x <= 0 && y <= 0) {
        std::cout << -1 << std::endl;
        return 0;
    }

    if (x < 0) {
        std::swap(x, y);
    }

    long long operations = 0;

    while (y < m) {
        if (x >= y) {
            y += x;
        } else {
            x += y;
        }
        ++operations;
    }

    std::cout << operations << std::endl;

    return 0;
}