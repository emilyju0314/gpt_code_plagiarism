#include <iostream>
#include <vector>

using namespace std;
const int MOD = 998244353;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    dp[0][0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = (dp[i-1][j-1] + 1LL*j*dp[i-1][j]) % MOD;
        }
    }

    for(int k = 1; k <= n; k++) {
        int result = 0;
        for(int i = 1; i <= n; i++) {
            result = (result + dp[n][i]) % MOD;
        }
        cout << result << " ";
    }

    return 0;
}