#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long mod = 998244353;

vector<vector<long long>> dp(1005, vector<long long>(1005));

long long power(long long x, long long n) {
    long long res = 1;
    while (n) {
        if (n & 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    long long M, N, K;
    cin >> M >> N >> K;

    long long ans = 0;

    for (int i = 0; i <= K; ++i) {
        dp[0][i] = power(M - i, N);
    }

    for (int i = 1; i <= K; ++i) {
        for (int j = 0; j <= K; ++j) {
            dp[i][j] = dp[i - 1][j] - dp[i - 1][j + 1];
            dp[i][j] = (dp[i][j] + mod) % mod;
        }
    }

    for (int i = 0; i <= K; ++i) {
        ans = (ans + dp[i][0]) % mod;
    }

    cout << ans << endl;

    return 0;
}