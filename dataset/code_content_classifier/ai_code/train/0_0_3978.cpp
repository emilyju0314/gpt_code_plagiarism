#include <iostream>
#include <cmath>

int main() {
    double R;
    
    while (std::cin >> R) {
        if (R == 0.0) {
            break;
        }

        int denominator = 1;
        bool found = false;
        
        for (int numerator = 3; !found; ++numerator) {
            for (; denominator <= 3333333; ++denominator) {
                double pi = static_cast<double>(numerator) / denominator;
                
                if (std::abs(M_PI - pi) <= R) {
                    found = true;
                    break;
                }
            }
        }

        std::cout << numerator << "/" << denominator << std::endl;
    }

    return 0;
}