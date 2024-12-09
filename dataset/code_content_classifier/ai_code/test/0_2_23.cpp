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

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i = m; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + j * a[i-1]);
        }
    }

    int ans = 0;
    for(int i = 0; i <= n; i++) {
        ans = max(ans, dp[i][m]);
    }

    cout << ans << endl;

    return 0;
}