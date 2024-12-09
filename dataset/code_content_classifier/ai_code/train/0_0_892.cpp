#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MOD = 998244353;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> d(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> d[i][j];
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(1 << n, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            for (int j = 0; j < m; j++) {
                int city = d[i - 1][j] - 1;
                dp[i][mask | (1 << city)] = (dp[i][mask | (1 << city)] + dp[i - 1][mask]) % MOD;
            }
        }
    }

    long long ans = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        int countCities = __builtin_popcount(mask);
        if (countCities == n) {
            int inv = 1;
            for (int i = 1; i <= n; i++) {
                inv = (1LL * inv * i) % MOD;
            }
            inv = inv % MOD;
            ans = (ans + dp[n][mask] * inv) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}