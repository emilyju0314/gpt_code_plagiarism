#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, a, b, k;
    cin >> n >> a >> b >> k;

    vector<int> dp(n + 1), pref(n + 1);

    // Initialize the previous floor distances
    for (int i = 1; i <= n; i++) {
        dp[i] = (abs(i - a) < abs(b - a));
    }

    // Dynamic Programming to compute the number of sequences
    for (int i = 1; i < k; i++) {
        // Compute prefix sum
        pref[0] = dp[0];
        for (int j = 1; j <= n; j++) {
            pref[j] = (pref[j - 1] + dp[j]) % MOD;
        }

        // Compute updated dp values
        for (int j = 1; j <= n; j++) {
            int l = max(1, j - abs(b - a) + 1);
            int r = min(n, j + abs(b - a) - 1);
            dp[j] = (pref[r] - pref[l - 1] + MOD) % MOD;
        }
    }

    // Compute the total number of distinct number sequences
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + dp[i]) % MOD;
    }

    cout << ans << endl;

    return 0;
}