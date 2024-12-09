#include <iostream>
#include <vector>

#define MOD 998244353

long long power(long long base, long long exponent) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exponent /= 2;
    }
    return result;
}

int main() {
    int n, k;
    long long l;
    std::cin >> n >> k >> l;
    
    std::vector<long long> dp(n+1, 0);
    std::vector<long long> sum(n+1, 0);
    dp[0] = sum[0] = 1;
    
    for (int i = 1; i <= n; i++) {
        dp[i] = (sum[i-1] * power(i, MOD-2)) % MOD;
        sum[i] = (sum[i-1] + dp[i]) % MOD;
    }
    
    long long result = 0;
    for (int i = k; i <= n; i++) {
        result = (result + (dp[i] * (n-i+1) % MOD) * power(i-k+1, MOD-2) % MOD) % MOD;
    }
    
    result = (result * l) % MOD;
    
    std::cout << result << std::endl;
    
    return 0;
}