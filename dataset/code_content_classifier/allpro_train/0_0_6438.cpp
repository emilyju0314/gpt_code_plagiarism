#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> u(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> u[i][j];
        }
    }

    vector<vector<int>> dp(n+1, vector<int>(k+1, INT_MAX/2));
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(i, k); j++) {
            for (int p = 0; p < i; p++) {
                int unfamiliar = 0;
                for (int q = p; q < i; q++) {
                    unfamiliar += u[q][i-1];
                }
                dp[i][j] = min(dp[i][j], dp[p][j-1] + unfamiliar);
            }
        }
    }

    cout << dp[n][k] << endl;

    return 0;
}