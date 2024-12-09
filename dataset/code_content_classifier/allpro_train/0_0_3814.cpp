#include <iostream>
#include <cmath>

bool isPrime(long long n) {
    if(n <= 1) {
        return false;
    }
    if(n <= 3) {
        return true;
    }
    if(n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for(int i = 5; i * i <= n; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        long long a, b;
        std::cin >> a >> b;

        long long area = a * a - b * b;
        
        if(isPrime(area)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}