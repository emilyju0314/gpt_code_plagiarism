#include <iostream>
#include <vector>

const long long MOD = 1000000007;

std::vector<int> primeDivisors(int x) {
    std::vector<int> divisors;
    for(int p = 2; p * p <= x; p++) {
        if(x % p == 0) {
            divisors.push_back(p);
            while(x % p == 0) {
                x /= p;
            }
        }
    }
    if(x > 1) {
        divisors.push_back(x);
    }
    return divisors;
}

int maxPower(int x, int p) {
    int power = 0;
    while(x % p == 0) {
        x /= p;
        power++;
    }
    return power;
}

int f(int x, int y) {
    std::vector<int> primes = primeDivisors(x);
    int result = 1;
    for(int p : primes) {
        result = (result * maxPower(y, p)) % MOD;
    }
    return result;
}

long long calculateFormula(int x, long long n) {
    long long result = 1;
    for(long long i = 1; i <= n; i++) {
        result = (result * f(x, i)) % MOD;
    }
    return result;
}

int main() {
    int x;
    long long n;
    std::cin >> x >> n;
    
    std::cout << calculateFormula(x, n) << std::endl;

    return 0;
}