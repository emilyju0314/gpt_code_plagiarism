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

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for(int i = m; i <= n; i++) {
        dp[i][m] = a[i-1];
        for(int j = m - 1; j <= i - 1; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + m * a[i-1] - j * a[i-1]);
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}