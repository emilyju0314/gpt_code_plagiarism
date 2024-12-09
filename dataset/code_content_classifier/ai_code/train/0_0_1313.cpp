#include <iostream>
#include <cmath>

int main() {
    int n, r;
    std::cin >> n >> r;
    
    double R = r / sin(M_PI / n);
    
    std::cout << std::fixed;
    std::cout.precision(7);
    std::cout << R << std::endl;
    
    return 0;
}