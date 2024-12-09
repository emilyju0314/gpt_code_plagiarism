#include <iostream>

long long calculateF(long long n) {
    // If n is even, f(n) = n/2. If n is odd, f(n) = -((n+1)/2)
    if (n % 2 == 0) {
        return n / 2;
    } else {
        return -((n + 1) / 2);
    }
}

int main() {
    long long n;
    std::cin >> n;
    
    long long result = calculateF(n);
    
    std::cout << result << std::endl;
    
    return 0;
}