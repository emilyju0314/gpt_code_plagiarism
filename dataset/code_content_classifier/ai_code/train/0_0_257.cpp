#include <iostream>
#include <vector>

#define MOD 998244353

using namespace std;

int main() {
    int p, s, r;
    cin >> p >> s >> r;

    vector<vector<long long>> dp(p + 1, vector<long long>(s + 1, 0));

    dp[0][0] = 1;

    for (int i = 1; i <= p; i++) {
        for (int j = 0; j <= s; j++) {
            for (int k = r; k <= j; k++) {
                dp[i][j] += dp[i - 1][j - k];
                dp[i][j] %= MOD;
            }
        }
    }

    long long total_ways = 0;
    long long win_ways = 0;

    for (int i = r; i <= s; i++) {
        total_ways += dp[p][i];
        total_ways %= MOD;

        if (i > r) {
            win_ways += dp[p][i];
            win_ways %= MOD;
        }
    }

    long long inverse_q = 1;
    for (long long q = MOD - 2; q; q >>= 1) {
        if (q & 1) {
            inverse_q *= total_ways;
            inverse_q %= MOD;
        }
        total_ways *= total_ways;
        total_ways %= MOD;
    }

    long long result = (win_ways * inverse_q) % MOD;
    cout << result << endl;

    return 0;
}