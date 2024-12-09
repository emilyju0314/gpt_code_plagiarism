#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

long long power(long long x, long long y, int p) {
    long long res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1) {
            res = (res * x) % p;
        }
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int main() {
    int n, m, k, p;
    cin >> n >> m >> k >> p;

    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
    vector<vector<vector<long long>>>
        f(n + 1, vector<vector<long long>>(k + 1, vector<long long>(m + 1, 0)));

    for (int j = 0; j <= m; j++) {
        dp[1][j] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = (dp[i - 1][j - 1] * j + dp[i - 1][j] * (j + 1)) % MOD;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int K = 1; K <= k; K++) {
            f[i][K][0] = power(dp[i][m], K, MOD);
        }
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            for (int j = 1; j <= m; j++) {
                for (int p = 1; p <= k; p++) {
                    f[i][p][j] = 0;
                }
            }

            for (int j = i; j < i + len; j++) {
                for (int w = 1; w <= m; w++) {
                    for (int p = 1; p <= k; p++) {
                        for (int t = 0; t <= p; t++) {
                            if (p - t <= m && p - t >= 0) {
                                f[i][p][w] += f[j + 1][t][w - 1] * dp[len - (j - i + 1)][p - t];
                                f[i][p][w] %= MOD;
                            }
                        }
                    }
                }
            }
        }
    }

    long long answer = 0;
    for (int i = 1; i <= n; i++) {
        answer += f[1][k][i];
        answer %= MOD;
    }

    cout << answer << endl;

    return 0;
}