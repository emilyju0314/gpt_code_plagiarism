#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
    dp[0][0] = 1;

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            dp[i + 1][j] += dp[i][j];
            dp[i + 1][j] %= MOD;

            dp[i][j + 1] += dp[i][j];
            dp[i][j + 1] %= MOD;

            dp[i + 1][j + 1] += dp[i][j];
            dp[i + 1][j + 1] %= MOD;
        }
    }

    int ans = dp[N][M];
    cout << ans << endl;

    return 0;
}