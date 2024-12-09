#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, p;
        cin >> n >> p;

        vector<int> k(n);
        for (int i = 0; i < n; i++) {
            cin >> k[i];
        }

        sort(k.begin(), k.end(), greater<int>());

        vector<long long> dp(p, 0), next_dp(p, 0);
        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            fill(next_dp.begin(), next_dp.end(), 0);

            for (int j = 0; j < p; j++) {
                if (dp[j] > 0) {
                    next_dp[(j + k[i]) % p] = (next_dp[(j + k[i]) % p] + dp[j]) % MOD;
                    next_dp[j] = (next_dp[j] + dp[j]) % MOD;
                }
            }

            dp = next_dp;
        }

        long long ans = 0;
        for (int i = 0; i < p; i++) {
            ans = (ans + min(i, p - i) * dp[i]) % MOD;
        }

        cout << ans << endl;
    }

    return 0;
}