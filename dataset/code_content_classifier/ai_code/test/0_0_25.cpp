#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    dp[1][0] = 1;
    dp[1][1] = 1;

    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % MOD;
            if(j >= m) {
                dp[i][j] = (dp[i][j] - dp[i-1][j-m] + MOD) % MOD;
            }
        }
    }

    int ans = (dp[n][m] - dp[n][m-1] + MOD) % MOD;
    cout << ans << endl;

    return 0;
}