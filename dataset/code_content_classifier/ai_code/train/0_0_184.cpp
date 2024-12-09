#include <iostream>
#include <cmath>

int main() {
    int T;
    std::cin >> T;

    for (int i = 0; i < T; i++) {
        int n;
        std::cin >> n;

        double angle = M_PI / (2 * n);
        double side_length = 1 / (2 * sin(angle));

        std::cout << std::fixed;
        std::cout.precision(9);
        std::cout << side_length << std::endl;
    }

    return 0;
}