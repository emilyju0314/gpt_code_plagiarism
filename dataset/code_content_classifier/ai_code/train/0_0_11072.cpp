#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 100000;

int main() {
    while (true) {
        int N, M, S;
        cin >> N >> M >> S;
        if (N == 0 && M == 0 && S == 0) {
            break;
        }

        vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(M + 1, vector<int>(S + 1, 0)));
        dp[0][0][0] = 1;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= M; j++) {
                for (int k = 0; k <= S; k++) {
                    if (j <= k) {
                        if (j != 0) {
                            dp[i + 1][j][k] = ((dp[i + 1][j][k] + dp[i][j - 1][k - j]) % MOD + dp[i + 1][j - 1][k - j]) % MOD;
                        }
                        dp[i + 1][j][k] = (dp[i + 1][j][k] + dp[i][j][k]) % MOD;
                    }
                }
            }
        }

        int ans = 0;
        for (int j = 0; j <= M; j++) {
            ans = (ans + dp[N][j][S]) % MOD;
        }

        cout << ans << endl;
    }

    return 0;
}