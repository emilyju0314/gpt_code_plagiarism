#include <iostream>
#include <vector>

const int MOD = 998244353;

int mod_pow(int base, int exponent) {
    int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exponent /= 2;
    }
    return result;
}

int mod_inv(int num) {
    return mod_pow(num, MOD - 2);
}

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> l(n), r(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> l[i] >> r[i];
    }
    
    std::vector<int> fact(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
    
    std::vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j >= 0; --j) {
            dp[j+1] = (dp[j+1] + (long long) dp[j] * (r[i] - l[i] + 1)) % MOD;
            dp[j] = (long long) dp[j] * (MOD + 1 - l[i]) % MOD;
        }
    }
    
    int ans = 0;
    for (int k = 0; k <= n; ++k) {
        ans = (ans + (long long) dp[k] * mod_inv(fact[k])) % MOD;
    }
    
    std::cout << ans << std::endl;
    
    return 0;
}