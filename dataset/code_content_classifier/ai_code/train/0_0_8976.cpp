#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, W, B, X;
    cin >> n >> W >> B >> X;

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vector<int> cost(n);
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            for (int k = 0; k <= c[i-1]; k++) {
                if (j - k * cost[i-1] >= 0) {
                    int mana_spent = k * cost[i-1];
                    int mana_restored = min(W - j + k * B, X);
                    dp[i][j] = max(dp[i][j], dp[i-1][j - mana_spent] + k);
                }
            }
        }
    }

    int max_birds = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            max_birds = max(max_birds, dp[i][j]);
        }
    }

    cout << max_birds << endl;

    return 0;
}