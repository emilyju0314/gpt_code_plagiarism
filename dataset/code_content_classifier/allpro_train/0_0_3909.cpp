#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> p(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> p[i][j];
        }
    }
    
    vector<vector<long long>> dp(1 << n, vector<long long>(n));
    dp[0][0] = 1;
    
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                for (int j = 0; j < n; j++) {
                    if (!(mask & (1 << j))) {
                        int prob = p[i][j];
                        long long cur = (dp[mask][i] * prob) % MOD;
                        dp[mask | (1 << j)][j] = (dp[mask | (1 << j)][j] + cur) % MOD;
                    }
                }
            }
        }
    }
    
    long long ans = dp[(1 << n) - 1][n - 1];
    cout << ans << endl;
    
    return 0;
}