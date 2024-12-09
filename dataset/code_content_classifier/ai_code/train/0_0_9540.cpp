#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, k, m;
    cin >> n >> k >> m;

    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(m+1, 0)));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j][1] = j * 2 % MOD;
            for (int len = 2; len <= m; len++) {
                int total = (i*(i-1)/2)% MOD + ((n-i+1)*(n-i)/2) % MOD;
                dp[i][j][len] = ((total - dp[i][j][len-1] * 2) % MOD + MOD) % MOD;
                for (int q = 0; q < i; q++) {
                    dp[i][j][len] = (dp[i][j][len] + 2 * dp[q][j][len-1]) % MOD;
                }
                for(int q = i+1; q <= n; q++){
                    dp[i][j][len] = (dp[i][j][len] + 2 * dp[q][j][len-2]) % MOD;
                }
            }
        }
    }

    cout << dp[n][k][m] << endl;

    return 0;
}