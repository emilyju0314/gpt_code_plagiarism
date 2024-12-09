#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int add(int a, int b) {
    return (a + b) % MOD;
}

int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            dp[i][j] = add(mul(dp[i-1][j], j), dp[i-1][j-1]);
        }
    }

    int ans = 0;
    for (int i = 0; i <= min(n, k); i++) {
        ans = add(ans, mul(dp[n][i], dp[n][k-i]));
    }

    cout << ans << endl;

    return 0;
}