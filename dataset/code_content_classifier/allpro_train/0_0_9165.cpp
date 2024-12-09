#include <iostream>

int main() {
    int x, y;
    std::cin >> x >> y;

    // Calculate the number of points where the wire intersects with the panel boundaries
    int numPoints = x + y;

    std::cout << numPoints << std::endl;

    return 0;
}