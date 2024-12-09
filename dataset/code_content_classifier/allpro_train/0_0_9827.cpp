#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(2, 0)));
    dp[0][0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int l = 0; l <= 1; l++) {
                if (sequence[i] == 2 || sequence[i] == 0) {
                    dp[i + 1][j][0] = (dp[i + 1][j][0] + dp[i][j][l]) % MOD;
                }
                if (sequence[i] == 4 || sequence[i] == 0) {
                    int nj = min(k, j + 1);
                    dp[i + 1][nj][1] = (dp[i + 1][nj][1] + dp[i][j][l]) % MOD;
                }
            }
        }
    }

    int ans = 0;
    for (int j = 0; j <= k; j++) {
        ans = (ans + dp[n][j][1]) % MOD;
    }

    cout << ans << endl;

    return 0;
}