#include <iostream>
#include <cmath>

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (int i = 5; i <= sqrt(n); i+=6) {
        if (n % i == 0 || n % (i+2) == 0) {
            return false;
        }
    }
    
    return true;
}

int next_prime(int n) {
    int next = n + 1;
    while (!is_prime(next)) {
        next++;
    }
    return next;
}

int prev_prime(int n) {
    int prev = n - 1;
    while (!is_prime(prev)) {
        prev--;
    }
    return prev;
}

int main() {
    int t;
    std::cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        
        int p = prev_prime(n);
        int q = next_prime(n);
        
        int numerator = p*q - p - q + 1;
        int denominator = 2*p*q;
        
        std::cout << numerator << "/" << denominator << std::endl;
    }
    
    return 0;
}