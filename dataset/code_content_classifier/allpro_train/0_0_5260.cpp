#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 998244353;

int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int max_sum = 300 * 300;
    vector<vector<int>> dp(N + 1, vector<int>(max_sum + 1));
    dp[0][0] = 1;

    for (int i = 0; i < N; i++) {
        vector<vector<int>> new_dp(N + 1, vector<int>(max_sum + 1));
        for (int j = 0; j <= N; j++) {
            for (int k = 0; k <= max_sum; k++) {
                new_dp[j][k] = dp[j][k];
                if (j >= 1 && k + a[i] <= max_sum) {
                    new_dp[j][k + a[i]] += dp[j - 1][k];
                }
                new_dp[j][k] %= MOD;
            }
        }
        dp = new_dp;
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j * 2 <= max_sum; j++) {
            ans = (ans + dp[i][j]) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}