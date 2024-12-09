#include <iostream>
#include <cmath>

int main() {
    int numCases;
    std::cin >> numCases;
    
    for (int i = 0; i < numCases; i++) {
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;
        
        // Calculate discriminant
        int discriminant = pow(b, 2) - (4 * a * c);
        
        if (discriminant > 0) {
            // Two distinct real roots
            int positiveRoots = 2;
            int negativeRoots = 1;
            std::cout << positiveRoots << " " << negativeRoots << std::endl;
        } else if (discriminant == 0) {
            // One real root
            int positiveRoots = 1;
            int negativeRoots = 0;
            std::cout << positiveRoots << " " << negativeRoots << std::endl;
        } else {
            // No real roots
            int positiveRoots = 0;
            int negativeRoots = 0;
            std::cout << positiveRoots << " " << negativeRoots << std::endl;
        }
    }
    
    return 0;
}