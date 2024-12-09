#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int power(int x, int y) {
    int res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res = (1LL * res * x) % MOD;
        }
        x = (1LL * x * x) % MOD;
        y /= 2;
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i = 1; i <= n; i++) {
        dp[i][0] = (1LL * dp[i-1][0] * i + 1) % MOD;
    }

    for (int j = 1; j <= m; j++) {
        dp[0][j] = (1LL * dp[0][j-1] * (m-j) + 1) % MOD;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int inv = power(i + m - j, MOD - 2);
            dp[i][j] = ((1LL * dp[i-1][j] * i + 1LL * dp[i][j-1] * (m-j)) % MOD * inv) % MOD;
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}