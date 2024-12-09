#include <iostream>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int a1, b1, a2, b2;
        std::cin >> a1 >> b1 >> a2 >> b2;

        // Check if it is possible to form a square
        if ((a1 + a2 == b1 && a1 + a2 == b2) || 
            (a1 + b2 == b1 && a1 + b2 == a2) || 
            (b1 + a2 == a1 && b1 + a2 == b2) || 
            (b1 + b2 == a1 && b1 + b2 == a2)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}