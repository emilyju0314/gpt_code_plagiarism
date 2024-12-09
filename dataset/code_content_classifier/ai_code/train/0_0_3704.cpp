#include <iostream>
#include <vector>

using namespace std;
const int MOD = 1000000007;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> dp(n + 1, vector<int>(n * n + 1));
    dp[0][0] = 1;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n * n; j++) {
            dp[i][j] = (dp[i][j] + dp[i - 1][j] * 2) % MOD;
            if (j >= i) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - i]) % MOD;
            }
        }
    }
    
    cout << dp[n][k] << endl;

    return 0;
}