#include <iostream>

int main() {
    int n, x, y;
    std::cin >> n >> x >> y;

    // Check if the marked cell is located on a diagonal of the square
    if ((x == n/2 || x == n/2 + 1) && (y == n/2 || y == n/2 + 1)) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl;
    }

    return 0;
}