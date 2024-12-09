#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

long long power(long long x, long long y, long long p) {
    long long res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1) {
            res = (res * x) % p;
        }
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> primes(n);
    for (int i = 0; i < n; i++) {
        std::cin >> primes[i];
    }
    
    long long result = 1;
    for (int i = 0; i < n; i++) {
        result = (result * (primes[i] - 1)) % MOD;
    }
    
    std::cout << result << std::endl;
    
    return 0;
}