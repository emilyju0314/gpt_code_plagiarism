#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;

    vector<int> throws(n);
    for (int i = 0; i < n; i++) {
        cin >> throws[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>((1 << n), 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            for (int j = 0; j < n; j++) {
                if ((mask & (1 << j)) == 0) {
                    if (throws[j] == 1) {
                        int k = __builtin_popcount(mask);
                        dp[i][mask | (1 << j)] = (dp[i][mask | (1 << j)] + dp[i - 1][mask]) % MOD;
                    } else {
                        for (int k = j + 1; k < n; k++) {
                            if ((mask & (1 << k)) == 0) {
                                dp[i][mask | (1 << j) | (1 << k)] = (dp[i][mask | (1 << j) | (1 << k)] + dp[i - 1][mask]) % MOD;
                            }
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        if (__builtin_popcount(mask) == n) {
            ans = (ans + dp[n][mask]) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}