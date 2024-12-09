#include <iostream>
#include <cmath>

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

int main() {
    int P, Q, R;
    
    while (true) {
        std::cin >> P >> Q >> R;
        if (P == 0 && Q == 0 && R == 0) break;
        
        double L = 2 * M_PI * P * gcd(Q, P) / gcd(Q, P);
        L += 2 * M_PI * R;
        
        std::cout << std::fixed;
        std::cout.precision(2);
        std::cout << L << std::endl;
    }
    
    return 0;
}