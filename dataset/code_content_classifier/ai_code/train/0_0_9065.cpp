#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    while (q--) {
        int l, x;
        cin >> l >> x;

        vector<int> dp(1 << 20, 0);
        dp[0] = 1;

        for (int i = 0; i < l; i++) {
            vector<int> new_dp(1 << 20, 0);
            for (int j = 0; j < (1 << 20); j++) {
                new_dp[j] += dp[j] + dp[j ^ a[i]];
                new_dp[j] %= MOD;
            }
            dp = new_dp;
        }

        cout << dp[x] << endl;
    }

    return 0;
}