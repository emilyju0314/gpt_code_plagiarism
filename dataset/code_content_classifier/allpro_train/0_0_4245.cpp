#include <iostream>
#include <cmath>

int main() {
    int c1x, c1y, c1r, c2x, c2y, c2r;
    
    // Input
    std::cin >> c1x >> c1y >> c1r >> c2x >> c2y >> c2r;
    
    // Calculate distance between the centers of the circles
    double distance = sqrt(pow(c2x - c1x, 2) + pow(c2y - c1y, 2));
    
    // Calculate sum and difference of the radii
    int sumRadius = c1r + c2r;
    int diffRadius = abs(c1r - c2r);
    
    // Output based on conditions
    if (distance == sumRadius) {
        std::cout << 3 << std::endl;
    } else if (distance > sumRadius) {
        std::cout<< 4 << std::endl;
    } else if (distance == diffRadius) {
        std::cout<< 1 << std::endl;
    } else if (distance < sumRadius && distance > diffRadius) {
        std::cout << 2 << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }
    
    return 0;
}