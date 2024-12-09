#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, p;
    cin >> n >> p;

    vector<vector<long long>> dp(n + 1, vector<long long>(p + 1));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= p; j++) {
            dp[i][j] = (2 * dp[i][j - 1] + dp[i - 1][j - 2] - dp[i - 1][max(j - 4, 0)]) % MOD;
        }
    }

    long long ways = (dp[n][p] - dp[n - 1][p] + MOD) % MOD;
    cout << ways << endl;

    return 0;
}