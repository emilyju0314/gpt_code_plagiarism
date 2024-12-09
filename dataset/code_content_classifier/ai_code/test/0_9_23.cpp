#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<vector<int>> dp(n+1, vector<int>(m+1));

    for(int i = m; i <= n; i++) {
        dp[i][1] = a[i-1];
    }

    for(int i = m+1; i <= n; i++) {
        for(int j = 2; j <= m; j++) {
            dp[i][j] = max(dp[i-1][j-1] + a[i-1] * (m-j+1), dp[i-1][j]);
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}