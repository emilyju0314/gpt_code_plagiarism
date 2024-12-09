#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        // Calculate prefix sum
        vector<int> prefix(k + 2, 0);
        for (int j = 0; j <= k; j++) {
            prefix[j + 1] = (prefix[j] + dp[i - 1][j]) % MOD;
        }

        for (int j = 0; j <= k; j++) {
            // Update dp[i][j] by considering all intervals [l, r]
            for (int l = 1; l <= i; l++) {
                for (int r = l; r <= i; r++) {
                    int cnt = (prefix[r - l + 1] - prefix[l - 1] + MOD) % MOD;
                    dp[i][j] = (dp[i][j] + ((long long)cnt * dp[i - r][j - 1]) % MOD) % MOD;
                }
            }
        }
    }

    cout << dp[n][k] << endl;

    return 0;
}