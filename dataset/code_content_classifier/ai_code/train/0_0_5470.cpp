#include <iostream>

using namespace std;

int main() {
    int n, m, t;
    cin >> n >> m >> t;

    long long dp[n+1][t+1];
    memset(dp, 0, sizeof(dp));

    for(int i = 4; i <= min(t-1, n); i++) {
        dp[i][i] = 1;
    }

    for(int i = 4; i <= n; i++) {
        for(int j = i + 1; j <= t; j++) {
            dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
            if(j <= m) {
                dp[i][j] += dp[i-1][j];
            }
        }
    }

    long long ways = 0;
    for(int i = 4; i <= n; i++) {
        ways += dp[i][t];
    }

    cout << ways << endl;
    
    return 0;
}