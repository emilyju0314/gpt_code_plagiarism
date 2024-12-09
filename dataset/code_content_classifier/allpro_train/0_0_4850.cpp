#include <iostream>
#include <cmath>

int main() {
    int n, a_x, a_y, b_x, b_y, c_x, c_y;
    std::cin >> n >> a_x >> a_y >> b_x >> b_y >> c_x >> c_y;

    if ((a_x == b_x && b_x == c_x) || (a_y == b_y && b_y == c_y) || (std::abs(a_x - b_x) == std::abs(a_y - b_y) && std::abs(b_x - c_x) == std::abs(b_y - c_y))) {
        std::cout << "NO";
    } else {
        std::cout << "YES";
    }

    return 0;
}