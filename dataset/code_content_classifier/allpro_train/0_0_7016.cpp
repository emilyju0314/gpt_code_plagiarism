#include <iostream>

int main() {
    int y, b, r;
    std::cin >> y >> b >> r;

    // Find the maximum possible value of y, b, and r satisfying the given conditions
    int maxOrnaments = std::min({y, b-1, r-2});
    
    // Calculate the total number of ornaments that can be used
    int totalOrnaments = maxOrnaments + maxOrnaments + 3;
    
    std::cout << totalOrnaments << std::endl;

    return 0;
}