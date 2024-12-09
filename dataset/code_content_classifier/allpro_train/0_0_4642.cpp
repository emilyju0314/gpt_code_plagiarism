#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> cakes(n);
    for (int i = 0; i < n; i++) {
        cin >> cakes[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = dp[i-1][j];
            int same = 0;
            int distinct = 0;
            for (int l = i; l > 0 && l > i - 50; l--) {
                if (same == 0 && distinct < j) {
                    distinct++;
                } else if (cakes[l-1] == cakes[i-1]) {
                    same++;
                }
                dp[i][j] = max(dp[i][j], dp[l-1][j-1] + same + distinct);
            }
        }
    }

    cout << dp[n][k] << endl;

    return 0;
}