#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        dp[1][i] = 1;
    }
    
    for (int i = 2; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            for (int l = j; l <= n; l += j) {
                dp[i][l] = (dp[i][l] + dp[i-1][j]) % MOD;
            }
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + dp[k][i]) % MOD;
    }
    
    cout << ans << endl;
    
    return 0;
}