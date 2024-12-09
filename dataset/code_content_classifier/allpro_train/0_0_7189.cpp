#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    int ans = 0;
    for (int k = 2; k <= n; k++) {
        for (int m = 1; m <= 200; m++) {
            vector<vector<int>> dp(k + 1, vector<int>(m + 1, -1));
            dp[0][0] = 0;

            for (int i = 0; i < n; i++) {
                for (int j = k; j >= 1; j--) {
                    for (int s = m; s >= weights[i]; s--) {
                        if (dp[j - 1][s - weights[i]] != -1) {
                            dp[j][s] = max(dp[j][s], dp[j - 1][s - weights[i]] + 1);
                        }
                    }
                }
            }

            if (dp[k][m] == n) {
                ans = max(ans, k);
            }
        }
    }

    cout << ans << endl;

    return 0;
}