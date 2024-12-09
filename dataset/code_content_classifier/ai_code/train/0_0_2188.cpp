#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MOD = 998244353;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> a(n+1, vector<int>(n+1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> dp(n+1, vector<int>(n+1));
    dp[0][0] = 1;

    for(int i = 1; i <= n; i++) {
        vector<int> pref(n+1);
        pref[0] = dp[i-1][0];
        for(int j = 1; j <= n; j++) {
            pref[j] = (pref[j-1] + dp[i-1][j]) % MOD;
        }

        for(int j = 1; j <= n; j++) {
            int best = pref[j];
            for(int k = j-1; k >= 0; k--) {
                best = min(best, pref[k] + a[j][i]);
                dp[i][j] = (dp[i][j] + best) % MOD;
            }
        }
    }

    vector<int> ans(n);
    for(int k = 1; k <= n; k++) {
        for(int j = 1; j <= n; j++) {
            ans[k-1] = (ans[k-1] + dp[k][j]) % MOD;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}