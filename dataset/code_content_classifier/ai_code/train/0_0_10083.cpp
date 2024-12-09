#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    vector<vector<long long>> dp(k + 1, vector<long long>(n, 0));

    for (int i = 1; i <= k; i++) {
        long long maxDiff = -prices[0];
        for (int j = 1; j < n; j++) {
            dp[i][j] = max(dp[i][j - 1], prices[j] + maxDiff);
            maxDiff = max(maxDiff, dp[i - 1][j] - prices[j]);
        }
    }

    cout << dp[k][n - 1] << endl;

    return 0;
}