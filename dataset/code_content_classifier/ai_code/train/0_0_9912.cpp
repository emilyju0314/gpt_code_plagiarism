#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> perm(n);
    for (int i = 0; i < n; i++) {
        cin >> perm[i];
    }

    vector<vector<int>> dp(1 << n, vector<int>(n + 1, 0));
    dp[0][0] = 1;

    for (int mask = 0; mask < (1 << n); mask++) {
        int cnt = __builtin_popcount(mask);
        if (cnt > k) continue;

        for (int j = 0; j < n; j++) {
            if (!((mask >> j) & 1)) {
                int new_mask = mask | (1 << j);
                for (int i = 0; i <= n; i++) {
                    dp[new_mask][i + 1] = (dp[new_mask][i + 1] + dp[mask][i]) % MOD;
                }
            }
        }
    }

    int ans = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        int cnt = __builtin_popcount(mask);
        if (cnt == k) {
            ans = (ans + dp[mask][n]) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}