#include <iostream>
#include <cmath>

int main() {
    int n, R, r;
    std::cin >> n >> R >> r;

    if (r > R) {
        std::cout << "NO" << std::endl;
    } else if (r * 2 > R && n > 1) {
        std::cout << "NO" << std::endl;
    } else {
        double angle = asin(r / (R - r));
        double total_angle = 2 * 3.14159265358979323846;
        if (n * angle <= total_angle) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}