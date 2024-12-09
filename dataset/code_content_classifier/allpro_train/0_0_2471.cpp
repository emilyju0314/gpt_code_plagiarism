#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<vector<double>> dp(n+1, vector<double>(k+1, 0.0));
    dp[0][0] = 0.0;

    for(int i = 1; i <= n; i++) {
        dp[i][0] = dp[i-1][0] + (p[i-1] - 1);
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            dp[i][j] = dp[i-1][j] * (i - (p[i-1] - p[i-2] - 1))/(i*(i+1)/2) + dp[i-1][j-1] * (1 - (i - (p[i-1] - p[i-2] - 1))/(i*(i+1)/2));
        }
    }

    double ans = 0.0;
    for(int i = 0; i <= k; i++) {
        ans += dp[n][i];
    }

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}