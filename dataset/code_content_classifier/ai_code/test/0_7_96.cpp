#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    int n, x;
    cin >> n >> x;

    vector<vector<int>> dp(n + 1, vector<int>(x + 1));

    dp[1][1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            for (int k = 1; k < j; k++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][__gcd(j, k)]) % MOD;
            }
        }
    }

    int ways = 0;
    for (int i = 1; i <= x; i++) {
        ways = (ways + dp[n][i]) % MOD;
    }

    cout << ways << endl;

    return 0;
}