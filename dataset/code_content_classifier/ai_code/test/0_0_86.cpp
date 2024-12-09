#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 998244353;

int power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result = (result * 2) % MOD;
    }
    return result;
}

int solve(int n, int k, int x) {
    if (n == 1) {
        return 1;
    }
    
    int p = power(2, std::min(k, 20));
    
    if (n % 2 == 0) {
        return (n % MOD * (p - 1)) % MOD;
    } else {
        return p;
    }
}

int main() {
    int t;
    std::cin >> t;
    
    while (t--) {
        int n, k, x;
        std::cin >> n >> k >> x;
        
        int result = solve(n, k, x);
        std::cout << result << std::endl;
    }
    
    return 0;
}