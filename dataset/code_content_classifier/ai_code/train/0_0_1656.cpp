#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<long long>> dp(k + 1, vector<long long>(n, 1e18));

    dp[0][0] = 0;
    for (int i = 1; i < n; i++) {
        dp[1][i] = max(dp[1][i-1], (long long)a[i] * (i+1));
    }
    
    for (int i = 2; i <= k; i++) {
        for (int j = i; j < n; j++) {
            long long curr_max = 0;
            for (int l = j; l >= i - 1; l--) {
                curr_max = max(curr_max, (long long)a[l] * (j - l + 1));
                dp[i][j] = min(dp[i][j], dp[i-1][l-1] + curr_max);
            }
        }
    }

    cout << dp[k][n-1] << endl;

    return 0;
}