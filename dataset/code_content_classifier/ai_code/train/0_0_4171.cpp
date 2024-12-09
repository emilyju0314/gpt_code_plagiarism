#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> dp(n + 1, vector<int>(k + 1));
    dp[0][0] = 1;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            dp[i][j] = (1LL * dp[i - 1][j] * (m - 1) % MOD + 1LL * dp[i - 1][j - 1] % MOD) % MOD;
        }
    }

    int result = 0;
    for(int i = 0; i <= k; i++) {
        result = (result + 1LL * dp[n][i] * dp[n][i] % MOD) % MOD;
    }

    cout << result << endl;

    return 0;
}