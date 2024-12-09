#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int beautifulStrings(int n, int m, int g) {
    vector<vector<long long>> dp(n + m + 1, vector<long long>(2, 0));
    dp[0][0] = 1;
    
    for (int i = 1; i <= n + m; i++) {
        dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % MOD;
        if (i >= 2) {
            dp[i][1] = dp[i-2][0];
        }
    }
    
    long long result = (dp[n+m][0] + dp[n+m][1]) % MOD;
    if (g == 0) {
        result = (result - dp[n][1] + MOD) % MOD;
    } else {
        result = (result - dp[m][0] + MOD) % MOD;
    }
    
    return result;
}

int main() {
    int n, m, g;
    cin >> n >> m >> g;
    
    int result = beautifulStrings(n, m, g);
    cout << result << endl;
    
    return 0;
}