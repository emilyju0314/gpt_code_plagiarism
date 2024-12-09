#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, x;
    cin >> n >> k >> x;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend());

    vector<vector<vector<int>> dp(n+1, vector<vector<int>>(x+1, vector<int>(k+1, -1)));
    dp[0][0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            for (int l = 1; l <= k; l++) {
                dp[i][j][l] = max(dp[i][j][l], dp[i-1][j-1][k-1] + a[i-1]);
            }
        }
    }

    if (dp[n][x][k] == -1) {
        cout << -1 << endl;
    } else {
        cout << dp[n][x][k] << endl;
    }

    return 0;
}