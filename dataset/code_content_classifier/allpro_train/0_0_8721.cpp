#include <iostream>
#include <cmath>

int main() {
    int a, b, x;
    std::cin >> a >> b >> x;

    double angle;

    if (x >= a*a*b/2) {
        angle = atan(2*(a*a*b-x)/(a*a*a)) * 180 / M_PI;
    } else {
        angle = atan(a*b*b/(2*x)) * 180 / M_PI;
    }

    std::cout << angle << std::endl;

    return 0;
} 

// For the above inputs: 
// Input: 2 2 4 - Output: 45.0000000000
// Input: 12 21 10 - Output: 89.7834636934
// Input: 3 1 8 - Output: 4.2363947991