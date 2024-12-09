#include <iostream>
#include <vector>
#include <cstring>

const int MOD = 1000000007;

int n, L;
int a[105], b[105];
long long dp[3005][105];

long long solve(int len, int prev) {
    if (len == L) {
        return 1;
    }

    if (dp[len][prev] != -1) {
        return dp[len][prev];
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (i != prev) {
            for (int j = 1; len + j <= L && a[i] == b[prev]; j++) {
                ans = (ans + solve(len + j, i)) % MOD;
            }
            for (int j = 1; len + j <= L && b[i] == b[prev]; j++) {
                ans = (ans + solve(len + j, i)) % MOD;
            }
        }
    }

    return dp[len][prev] = ans;
}

int main() {
    std::cin >> n >> L;

    for (int i = 0; i < n; i++) {
        std::cin >> a[i] >> b[i];
    }

    memset(dp, -1, sizeof(dp));

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + solve(a[i], i)) % MOD;
        ans = (ans + solve(b[i], i)) % MOD;
    }

    std::cout << ans << std::endl;

    return 0;
}