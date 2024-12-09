#include <iostream>
#include <cmath>

int main() {
    int t;
    std::cin >> t;
    
    for(int i = 0; i < t; i++) {
        int a;
        std::cin >> a;

        // Check if 360 degrees can be evenly divided by angle a
        if (360 % (180 - a) == 0) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}