#include <iostream>
#define MOD 1000000007

using namespace std;

int main() {
    int n, k, m;
    cin >> n >> k >> m;

    if (k > n || k == 1) {
        cout << n << endl;
    } else {
        long long dp[15][15][105] = {0};
        
        dp[0][0][0] = 1;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                for (int x = 1; x <= m; ++x) {
                    dp[i][j][x] = (dp[i-1][j-1][m] + dp[i-1][j][x-1]) % MOD;
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i <= m; ++i) {
            ans = (ans + dp[n-m+1][k-1][i]) % MOD;
        }
        cout << ans << endl;
    }

    return 0;
}