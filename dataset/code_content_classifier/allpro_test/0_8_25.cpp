#include <iostream>
#include <vector>

#define MOD 998244353

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<long long>> dp(n + 1, vector<long long>(m, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m - j; k++) {
                dp[i][j + k] = (dp[i][j + k] + dp[i - 1][j]) % MOD;
            }
        }
    }

    long long result = 0;
    for (int i = 0; i < m; i++) {
        result = (result + dp[n][i] * dp[n][i]) % MOD;
    }

    cout << result << endl;

    return 0;
}