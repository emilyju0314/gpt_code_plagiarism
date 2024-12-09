#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(k+1));

    for(int i = 1; i <= n; i++) {
        dp[i][1] = max(dp[i-1][1] + abs(nums[i-1] - nums[i]), abs(nums[i-1] - nums[i]));
    }

    for(int j = 2; j <= k; j++) {
        for(int i = 1; i <= n; i++) {
            int mx = 0;
            for(int l = i-1; l > 0; l--) {
                mx = max(mx, dp[l][j-1] + abs(nums[l-1] - nums[i-1]));
            }
            dp[i][j] = mx;
        }
    }

    cout << dp[n][k] << endl;

    return 0;
}