#include <iostream>
#include <cmath>

int main() {
    int A, B, n;
    std::cin >> A >> B >> n;
    
    if (A == 0 && B == 0) {
        std::cout << "5" << std::endl;
    } else if (A == 0) {
        std::cout << "No solution" << std::endl;
    } else {
        double X = pow(static_cast<double>(B)/A, static_cast<double>(1)/n);
        
        if (std::abs(X - static_cast<int>(X)) < 1e-9) { // Check if X is an integer
            std::cout << static_cast<int>(X) << std::endl;
        } else {
            std::cout << "No solution" << std::endl;
        }
    }
    
    return 0;
}