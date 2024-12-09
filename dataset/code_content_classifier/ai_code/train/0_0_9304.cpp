#include <iostream>
#include <cmath>

int main() {
    int a, b;
    std::cin >> a >> b;

    if (a == b) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl;
        int x1 = a, y1 = 0;
        int x2 = 0, y2 = b;
        int x3 = b, y3 = a;

        std::cout << x1 << " " << y1 << std::endl;
        std::cout << x2 << " " << y2 << std::endl;
        std::cout << x3 << " " << y3 << std::endl;
    }

    return 0;
}