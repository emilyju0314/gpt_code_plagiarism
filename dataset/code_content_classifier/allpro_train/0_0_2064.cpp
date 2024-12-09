#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int N, X, Y, Z;
    cin >> N >> X >> Y >> Z;

    vector<vector<vector<vector<int>>> dp(N + 1, vector<vector<vector<int>>>(11, vector<vector<int>>(11, vector<int>(11, 0))));
    dp[0][0][0][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= 10; j++) {
            for (int k = 0; k <= 10; k++) {
                for (int l = 0; l <= 10; l++) {
                    if (dp[i][j][k][l] == 0) continue;
                    for (int m = 1; m <= 10; m++) {
                        if (m == X && j < X) {
                            dp[i+1][m][k][l] = (dp[i+1][m][k][l] + dp[i][j][k][l]) % MOD;
                        }
                        if (m == Y && k < Y) {
                            dp[i+1][j][m][l] = (dp[i+1][j][m][l] + dp[i][j][k][l]) % MOD;
                        }
                        if (m == Z && l < Z) {
                            dp[i+1][j][k][m] = (dp[i+1][j][k][m] + dp[i][j][k][l]) % MOD;
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int j = 1; j <= 10; j++) {
        for (int k = 1; k <= 10; k++) {
            for (int l = 1; l <= 10; l++) {
                ans = (ans + dp[N][j][k][l]) % MOD;
            }
        }
    }

    cout << ans << endl;

    return 0;
}