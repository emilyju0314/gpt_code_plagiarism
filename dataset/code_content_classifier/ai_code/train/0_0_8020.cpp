#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> matrix(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            matrix[i][j] = row[j];
        }
    }

    vector<int> dp(1 << m, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vector<int> new_dp(1 << m, 0);
            for (int mask = 0; mask < (1 << m); mask++) {
                if (dp[mask] == 0) continue;

                if (matrix[i][j] == 'x' || (mask & (1 << j))) {
                    new_dp[mask & ~(1 << j)] = (new_dp[mask & ~(1 << j)] + dp[mask]) % MOD;
                } else {
                    if (j+1 < m && !(mask & (1 << (j+1))) && matrix[i][j+1] == '.') {
                        new_dp[mask | (1 << (j+1))] = (new_dp[mask | (1 << (j+1))] + dp[mask]) % MOD;
                    }
                    if (i+1 < n && matrix[i+1][j] == '.') {
                        new_dp[mask | (1 << j)] = (new_dp[mask | (1 << j)] + dp[mask]) % MOD;
                    }
                }
            }
            dp = new_dp;
        }
    }

    int ans = 0;
    for (int mask = 0; mask < (1 << m); mask++) {
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            if (!(mask & (1 << i))) {
                cnt++;
            }
        }
        if (cnt <= 1) {
            ans = (ans + dp[mask]) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}