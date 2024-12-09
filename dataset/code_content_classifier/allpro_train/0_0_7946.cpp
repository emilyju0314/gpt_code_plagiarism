#include <iostream>
#include <vector>
#include <cmath>

#define MOD 1000000007

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<pair<int, int>> intervals(Q);

    for (int i = 0; i < Q; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }

    vector<vector<long long>> dp(Q + 1, vector<long long>(9, 0));
    dp[0][0] = 1;

    for (int i = 0; i < Q; i++) {
        for (int j = 0; j < 9; j++) {
            for (int d = 0; d < 10; d++) {
                int rem = (j + d) % 9;
                dp[i + 1][rem] = (dp[i + 1][rem] + dp[i][j]) % MOD;
            }
        }
        for (int j = 0; j < 9; j++) {
            int l = intervals[i].first;
            int r = intervals[i].second;
            dp[i + 1][j] = (dp[i + 1][j] - dp[i][j] * ((r - l + 1) / 9) % MOD + MOD) % MOD;
        }
    }

    long long ans = 0;

    for (int i = 0; i < 9; i++) {
        ans = (ans + dp[Q][i]) % MOD;
    }

    long long res = 1;
    for (int i = 0; i < N; i++) {
        res = (res * 10) % MOD;
    }

    ans = (ans * (int) pow(res, MOD - 2)) % MOD; // Calculating modulo inverse
    cout << ans << endl;

    return 0;
}