#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<vector<double>> dp(n, vector<double>(k + 1, 0));
    for (int i = 0; i < n; i++) {
        dp[i][0] = 0;
    }

    for (int j = 1; j <= k; j++) {
        for (int i = 0; i < n; i++) {
            for (int l = i; l < n; l++) {
                dp[i][j] += (double)(max(0, p[l] - i) + max(0, l - p[i]) + 1) / (n*(n+1)/2) * dp[i][j-1];
            }
        }
    }

    double ans = 0.0;
    for (int i = 0; i < n; i++) {
        ans += dp[i][k];
    }

    cout << fixed << setprecision(12) << ans << endl;

    return 0;
}