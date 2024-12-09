#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> levels(n);
    for(int i = 0; i < n; i++) {
        cin >> levels[i];
    }

    vector<double> dp(n);
    for(int i = 1; i < n; i++) {
        dp[i] = dp[i-1] + levels[i] / 2.0;
    }

    double ans = dp[n-1];
    for(int i = 1; i < k; i++) {
        vector<double> new_dp(n);
        new_dp[0] = levels[0] / 2.0;
        for(int j = 1; j < n; j++) {
            new_dp[j] = new_dp[j-1] + levels[j] / 2.0;
        }

        for(int j = 2; j < n; j++) {
            double sum = 0;
            for(int l = 1; l <= j; l++) {
                sum += (levels[l]) / 2.0;
            }

            new_dp[j] = min(new_dp[j], dp[j-2] + sum);
        }

        dp = new_dp;
        ans = min(ans, dp[n-1]);
    }

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}