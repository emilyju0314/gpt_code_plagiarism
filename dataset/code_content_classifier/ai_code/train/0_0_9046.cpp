#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));

    for (int j = 1; j <= k; j++) {
        for (int i = 2; i <= n; i++) {
            dp[i][j] = dp[i-1][j];
            int max_diff = 0;
            for (int m = i-1; m >= 1; m--) {
                max_diff = max(max_diff, abs(nums[i] - nums[m]));
                dp[i][j] = max(dp[i][j], dp[m][j-1] + max_diff);
            }
        }
    }

    cout << dp[n][k] << endl;

    return 0;
}