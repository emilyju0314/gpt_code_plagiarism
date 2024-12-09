#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int total_hexagons = 3 * n * (n + 1) + 1;
    std::cout << total_hexagons << std::endl;

    return 0;
}