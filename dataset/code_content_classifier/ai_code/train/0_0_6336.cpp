#include <iostream>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        int a, b;
        std::cin >> a >> b;

        // Calculate the side length of the square land
        int side = std::max(2 * std::max(a, b), std::min(a, b));

        // Calculate the minimum area of the square land
        int min_area = side * side;

        std::cout << min_area << std::endl;
    }

    return 0;
}