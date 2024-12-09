#include <iostream>
#include <vector>

const long long MOD = 1000000007;

// Function to calculate the factorial modulo MOD
long long factorial(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact = (fact * i) % MOD;
    }
    return fact;
}

// Function to calculate the power modulo MOD
long long power(int base, int exp) {
    long long result = 1;
    base = base % MOD;
    
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        
        exp = exp >> 1;
        base = (base * base) % MOD;
    }
    
    return result;
}

// Function to solve the problem for each test case
void solve() {
    int n;
    std::cin >> n;
    
    long long ans = factorial(2 * n) * power(factorial(n), MOD-2) % MOD * power(factorial(n), MOD-2) % MOD;
    
    std::cout << ans << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}