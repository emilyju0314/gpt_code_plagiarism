#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 2, vector<int>(n + 2, 0)));
    
    // Initialize base cases
    for (int i = 1; i <= n + 1; i++) {
        dp[1][i][i] = 1;
    }

    // Fill the dp table
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n + 1; j++) {
            for (int k = 1; k <= n + 1; k++) {
                for (int l = k; l <= j; l++) {
                    dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][l]) % m;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= n + 1; j++) {
            ans = (ans + dp[n][i][j]) % m;
        }
    }

    cout << ans << endl;

    return 0;
}