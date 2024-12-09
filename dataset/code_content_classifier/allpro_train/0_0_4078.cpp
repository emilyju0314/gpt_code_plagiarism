#include <iostream>
#include <cmath>

bool isPrime(int n) {
    if(n <= 1) {
        return false;
    }
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

bool isLuckyForBob(int n) {
    for(int a = 1; a * a <= n; a++) {
        int b = sqrt(n - a * a);
        if(a * a + b * b == n) {
            return true;
        }
    }
    return false;
}

int main() {
    int l, r;
    std::cin >> l >> r;
    
    int count = 0;
    for(int i = l; i <= r; i++) {
        if(isPrime(i) && isLuckyForBob(i)) {
            count++;
        }
    }
    
    std::cout << count << std::endl;
    
    return 0;
}