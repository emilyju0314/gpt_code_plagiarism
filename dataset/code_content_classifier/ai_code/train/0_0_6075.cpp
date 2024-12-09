#include <iostream>
#include <vector>
#include <unordered_set>

const int MOD = 998244353;

int power(int x, int y) {
    int res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res = (res * x) % MOD;
        }
        x = (x * x) % MOD;
        y /= 2;
    }
    return res;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    
    std::vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        dp[i] = power(n / i, k);
    }
    
    std::vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = (dp[i] + pref[i - 1]) % MOD;
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + (dp[i] * pref[n / i]) % MOD) % MOD;
    }
    
    std::cout << ans << std::endl;
    
    return 0;
}