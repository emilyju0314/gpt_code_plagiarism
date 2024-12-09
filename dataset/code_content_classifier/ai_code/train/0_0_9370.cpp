#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, p, k;
    cin >> n >> p >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> s(n, vector<int>(p));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            cin >> s[i][j];
        }
    }

    vector<long long> dp(1 << n, -1e18);
    dp[0] = 0;

    for (int mask = 0; mask < (1 << n); mask++) {
        int selected = __builtin_popcount(mask);
        if (selected > p + k) continue;

        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) == 0) {
                int audience_contribution = selected <= k ? a[i] : 0;

                for (int j = 0; j < p; j++) {
                    dp[mask | (1 << i)] = max(dp[mask | (1 << i)], dp[mask] + s[i][j] + audience_contribution);
                }
            }
        }
    }

    cout << dp[(1 << n) - 1] << endl;

    return 0;
}