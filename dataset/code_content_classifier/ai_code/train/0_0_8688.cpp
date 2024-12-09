#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

int main() {
    int n, q, t;
    cin >> n >> q >> t;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<pair<int, int>> pairs(q);
    for (int i = 0; i < q; i++) {
        cin >> pairs[i].first >> pairs[i].second;
    }

    vector<int> dp(t + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = a[i]; j <= t; j++) {
            dp[j] = (dp[j] + dp[j - a[i]]) % MOD;
        }
    }

    for (auto pair : pairs) {
        if (dp[a[pair.first - 1]] >= dp[a[pair.second - 1]]) {
            cout << 0 << endl;
            return 0;
        }
    }

    cout << dp[t] << endl;

    return 0;
}