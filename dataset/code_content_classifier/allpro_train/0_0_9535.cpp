#include <iostream>
#include <cmath>

bool solveTest(int d) {
    if (d == 0) {
        std::cout << "Y 0.000000000 0.000000000\n";
        return true;
    }
    
    double discriminant = d * d - 4 * d;
    if (discriminant < 0) {
        std::cout << "N\n";
        return false;
    }
    
    double a = (d - sqrt(discriminant)) / 2;
    double b = d - a;
    
    std::cout.precision(9);
    std::cout << "Y " << std::fixed << a << " " << b << "\n";
    
    return true;
}

int main() {
    int t;
    std::cin >> t;
    
    while (t--) {
        int d;
        std::cin >> d;
        solveTest(d);
    }
    
    return 0;
}