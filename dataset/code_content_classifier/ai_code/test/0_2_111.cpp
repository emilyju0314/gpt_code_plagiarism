#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2*n+1, vector<int>(2*k+2, 0)));
    
    dp[0][0][k] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 2 * n; j++) {
            for (int l = 0; l <= 2 * k; l++) {
                if (dp[i][j][l] != 0) {
                    for (int x = 0; x <= 1; x++) {
                        int nj = j + x;
                        int nl = max(0, min(2*k, l + x - b[i] + k));
                        dp[i+1][nj][nl] = (dp[i+1][nj][nl] + dp[i][j][l]) % MOD;

                        if (x == 1) {
                            int nk = max(0, min(2*k, l - b[i] + k));
                            dp[i+1][nj][nk] = (dp[i+1][nj][nk] + dp[i][j][l]) % MOD;
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int j = 0; j <= 2 * n; j++) {
        for (int l = 0; l <= 2 * k; l++) {
            ans = (ans + dp[n][j][l]) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}