#include <iostream>
#include <vector>

using namespace std;

int minPalindromes(vector<int>& colors) {
    int n = colors.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 1; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            if (len == 1) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = 1 + dp[i+1][j];
                for (int k = i+1; k <= j; k++) {
                    if (colors[i] == colors[k]) {
                        dp[i][j] = min(dp[i][j], (k == i+1 ? 1 : dp[i+1][k-1]) + dp[k+1][j]);
                    }
                }
            }
        }
    }

    return dp[0][n-1];
}

int main() {
    int n;
    cin >> n;
    vector<int> colors(n);

    for (int i = 0; i < n; i++) {
        cin >> colors[i];
    }

    cout << minPalindromes(colors) << endl;

    return 0;
}