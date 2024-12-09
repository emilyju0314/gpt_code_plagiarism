#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n, t;
    double p;

    cin >> n >> p >> t;

    double dp[n+1][t+1];
    dp[0][0] = 1.0;

    for (int i = 1; i <= t; i++) {
        dp[0][i] = dp[0][i-1] * (1 - p);
        for (int j = 1; j <= n; j++) {
            dp[j][i] = dp[j-1][i-1] * p + dp[j][i-1] * (1 - p);
        }
    }

    double ans = 0.0;
    for (int i = 0; i <= n; i++) {
        ans += dp[i][t] * i;
    }

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}