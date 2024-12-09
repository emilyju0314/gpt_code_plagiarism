#include <iostream>

// Function to calculate GCD
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to calculate LCM
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int a, b;
    
    while (std::cin >> a >> b) {
        int gcd_val = gcd(a, b);
        int lcm_val = lcm(a, b);
        
        std::cout << gcd_val << " " << lcm_val << std::endl;
    }
    
    return 0;
}