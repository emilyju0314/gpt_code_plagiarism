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

    sort(a.begin(), a.end(), greater<int>());

    long long ans = 0;
    vector<vector<long long>> dp(m+1, vector<long long>(m+1, 0));

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= i; j++) {
            dp[i][j] = dp[i-1][j-1] + a[i-1] * (m-i+j);
            ans = max(ans, dp[i][j] - dp[i-1][j]);
        }
    }

    cout << ans << endl;

    return 0;
}