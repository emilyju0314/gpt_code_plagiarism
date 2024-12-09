#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    vector<vector<int>> cnt(n + 1, vector<int>(n + 1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            cnt[i][j] = cnt[i][j - 1] + (j - i) - (cnt[i][j - 1] - cnt[i][a[j - 1]]);
        }
    }

    for(int i = 1; i <= n; i++) {
        dp[i][1] = cnt[1][i];
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 2; j <= min(i, k); j++) {
            dp[i][j] = INT_MAX;
            for(int p = j - 1; p <= i - 1; p++) {
                dp[i][j] = min(dp[i][j], dp[p][j - 1] + cnt[p + 1][i]);
            }
        }
    }

    cout << dp[n][k] << endl;

    return 0;
}