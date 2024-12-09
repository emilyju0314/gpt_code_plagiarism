#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;

    vector<int> a(10);
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(1024, 0));
    dp[0][1023] = 1;

    for (int i = 1; i <= n; i++) {
        for (int mask = 0; mask < 1024; mask++) {
            for (int digit = 0; digit < 10; digit++) {
                if (mask & (1 << digit)) {
                    continue;
                }

                if (a[digit] == 0) {
                    continue;
                }

                int next_mask = mask | (1 << digit);
                dp[i][next_mask] += dp[i-1][mask];
                dp[i][next_mask] %= MOD;
            }
        }
    }

    long long ans = 0;
    for (int mask = 1; mask < 1024; mask++) {
        int count = 0;
        for (int i = 0; i < 10; i++) {
            if ((mask & (1 << i)) && a[i] > 0) {
                count += a[i];
            }
        }
        ans += dp[n][mask];
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}