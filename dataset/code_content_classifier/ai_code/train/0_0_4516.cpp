#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    // dp[i][j] represents the number of valid arrays of length i with maximum value j

    dp[0][0] = 1;

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int temp = (dp[m][i] * dp[m][n-i+1]) % MOD;
        ans = (ans + temp) % MOD;
    }

    cout << ans << endl;

    return 0;
}