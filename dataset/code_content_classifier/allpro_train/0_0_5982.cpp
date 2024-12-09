#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n, L;
    cin >> n >> L;

    vector<int> x(n+1), y(n+1);
    vector<double> s(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> s[i];
    }

    vector<double> dp(L+1, 1e18);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        dp[y[i]] = min(dp[y[i]], dp[x[i]] + (y[i] - x[i]) / (2 - s[i]));
        dp[y[i]] = min(dp[y[i]], dp[y[i]] + (1 - s[i]) * (y[i] - x[i]));
        dp[y[i]] = min(dp[y[i]], dp[x[i]] + (y[i] - x[i]) / s[i]);
    }

    cout << fixed << setprecision(12) << dp[L] << endl;

    return 0;
}