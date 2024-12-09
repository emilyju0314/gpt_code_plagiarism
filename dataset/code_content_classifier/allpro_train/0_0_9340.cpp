#include <iostream>
#include <cmath>

int main() {
    int q;
    double x, prev_x, diff;
    
    while (true) {
        std::cin >> q;
        if (q == -1) {
            break;
        }
        
        x = q / 2.0;
        do {
            prev_x = x;
            x = prev_x - (pow(prev_x, 3) - q) / (3 * pow(prev_x, 2));
            diff = fabs(pow(x, 3) - q);
        } while (diff > 0.00001 * q);
        
        std::cout << x << std::endl;
    }
    
    return 0;
}