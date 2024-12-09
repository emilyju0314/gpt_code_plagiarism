#include <iostream>
#include <cmath>

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    
    bool nIsPrime = isPrime(n);
    bool mIsPrime = isPrime(m);
    
    if (mIsPrime && m == n + 2) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    
    return 0;
}