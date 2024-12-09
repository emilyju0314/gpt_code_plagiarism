#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MOD = 998244353;

long long powmod(long long a, long long b) {
    long long res = 1;
    a %= MOD;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
    dp[1][0] = 1;
    dp[1][1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            dp[i][j] = (dp[i-1][j-1] * a + dp[i-1][j] * b) % MOD;
        }
    }

    long long numerator = dp[n][n];
    long long denominator = powmod(2, n);
    long long inv_denominator = powmod(denominator, MOD - 2);
    long long ans = (numerator * inv_denominator) % MOD;

    cout << (ans * denominator - 1 + MOD) % MOD << endl;

    return 0;
}