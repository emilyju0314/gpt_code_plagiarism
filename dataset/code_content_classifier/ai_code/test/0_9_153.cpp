#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    int n;
    cin >> n;

    vector<string> strings(n);
    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }

    int ans = 0;
    int m = 1 << n;

    for (int mask = 1; mask < m; mask++) {
        int value = 0;
        vector<vector<int>> dp(26, vector<int>(m, 0));

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                count++;
                for (char c : strings[i]) {
                    dp[c - 'a'][mask]++;
                }
            }
        }

        for (int i = 0; i < 26; i++) {
            dp[i][mask] += dp[i][mask ^ (1 << i)];
        }

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                for (char c : strings[i]) {
                    value = (value + dp[c - 'a'][mask] - 1) % MOD;
                }
            }
        }

        ans ^= (1LL * value * count) % MOD;
    }

    cout << ans << endl;

    return 0;
}