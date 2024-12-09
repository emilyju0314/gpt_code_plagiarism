#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> table(n, vector<int>(m));
    vector<vector<int>> dp(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> table[i][j];
        }
    }

    for (int j = 0; j < m; j++) {
        dp[0][j] = table[0][j];
    }

    for (int i = 1; i < n; i++) {
        vector<int> left(m), right(m);
        
        left[0] = dp[i - 1][0];
        for (int j = 1; j < m; j++) {
            left[j] = max(left[j - 1], dp[i - 1][j] + (j % 2 == 0 ? -table[i - 1][j] : table[i - 1][j]));
        }

        right[m - 1] = dp[i - 1][m - 1];
        for (int j = m - 2; j >= 0; j--) {
            right[j] = max(right[j + 1], dp[i - 1][j] + (j % 2 == 0 ? -table[i - 1][j] : table[i - 1][j]));
        }

        for (int j = 0; j < m; j++) {
            dp[i][j] = max(left[j], right[j]);
        }
    }

    int maxCoins = *max_element(dp[n - 1].begin(), dp[n - 1].end());
    cout << maxCoins << endl;

    return 0;
}