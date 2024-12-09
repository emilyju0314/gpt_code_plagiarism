#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> h(n);
    vector<vector<double>> dp(n, vector<double>(151, 1e9));
    vector<int> prefix_sum(n+1, 0);

    for (int i = 0; i < n; i++) {
        cin >> h[i];
        prefix_sum[i+1] = prefix_sum[i] + h[i];
    }

    dp[0][1] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 150; j++) {
            for (int k = 1; k <= j; k++) {
                double y = prefix_sum[i+1] - prefix_sum[i+1-k];
                double base = j - k;

                dp[i+1][j] = min(dp[i+1][j], dp[i][k] + y + 0.5 * (j + base) * (y / (j + base)));
            }
        }
    }

    cout << fixed << setprecision(8) << dp[n][1] << endl;

    return 0;
}