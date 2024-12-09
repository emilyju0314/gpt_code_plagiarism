#include <iostream>
#include <cmath>

int main() {
    int t;
    std::cin >> t;
    
    while (t--) {
        int n;
        std::cin >> n;
        
        int count = 0;
        count += std::sqrt(n); // Count of perfect squares
        count += std::cbrt(n); // Count of perfect cubes
        count -= std::pow((int)std::sqrt(n), 2); // Deduct count of numbers that are both squares and cubes
        
        std::cout << count << std::endl;
    }
    
    return 0;
}