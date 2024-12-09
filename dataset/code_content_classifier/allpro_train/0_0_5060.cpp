#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    vector<int> w(7);
    for (int i = 0; i < 7; i++) {
        cin >> w[i];
    }

    vector<vector<vector<long long>>> dp(8, vector<vector<long long>>(7, vector<long long>(1 << 7, 0)));
    dp[0][0][0] = 1;

    for (int i = 0; i < 7; i++) {
        for (int mask = 0; mask < (1 << 7); mask++) {
            if (dp[i][i][mask] == 0) continue;
            for (int j = i; j < 7; j++) {
                if (w[j] == 0 || ((mask >> j) & 1)) continue;
                int new_mask = mask | (1 << j);
                dp[i + 1][j][new_mask] = (dp[i + 1][j][new_mask] + dp[i][i][mask]) % MOD;
            }
        }

        for (int j = i + 1; j < 7; j++) {
            for (int mask = 0; mask < (1 << 7); mask++) {
                dp[i + 1][j][mask] = dp[i][j][mask];
            }
        }
    }

    long long ans = 0;
    for (int mask = 0; mask < (1 << 7); mask++) {
        ans = (ans + dp[7][6][mask]) % MOD;
    }

    cout << ans << endl;

    return 0;
}