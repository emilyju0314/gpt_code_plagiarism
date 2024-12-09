#include <iostream>
#include <cmath>

bool is_prime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    
    return true;
}

int main() {
    int t;
    std::cin >> t;
    
    for (int i = 0; i < t; i++) {
        long long n, k;
        std::cin >> n >> k;
        
        if (is_prime(n)) {
            std::cout << "NO" << std::endl;
        } else {
            std::cout << "YES" << std::endl;
        }
    }
    
    return 0;
}