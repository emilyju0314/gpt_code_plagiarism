#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 1000000007;

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    std::vector<long long> dp(n+1, 0);
    dp[0] = 1;

    int prev = 0;
    for (int i = 0; i < n; i++) {
        while (prev < n && a[prev] <= a[i] / (i+1)) {
            prev++;
        }

        dp[i+1] = (2 * dp[i]) % MOD;
        if (prev > 0 && a[prev-1] == a[i] / (i+1)) {
            dp[i+1] = (dp[i+1] + dp[prev-1]) % MOD;
        }
    }

    std::cout << (dp[n] - 1 + MOD) % MOD << std::endl;

    return 0;
}