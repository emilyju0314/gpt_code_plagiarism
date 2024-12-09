#include <iostream>
using namespace std;

const int MOD = 777777777;

int dp[2][1024][128];

int main() {
    int n, k;
    cin >> n >> k;

    dp[0][0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            for (int j = 0; j <= k; j++) {
                dp[i % 2][mask][j] = 0;
                for (int bit = 0; bit < n; bit++) {
                    if (mask & (1 << bit)) {
                        dp[i % 2][mask][j] += dp[(i - 1) % 2][mask ^ (1 << bit)][j - (bit < n / 2)];
                    } else {
                        dp[i % 2][mask][j] += dp[(i - 1) % 2][mask ^ (1 << bit)][j + (bit < n / 2)];
                    }
                    dp[i % 2][mask][j] %= MOD;
                }
            }
        }
    }

    cout << dp[n % 2][(1 << n) - 1][k] << endl;

    return 0;
}