#include <iostream>
#include <vector>

#define MOD 1000000009

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<bool>> obstacles(N, vector<bool>(N, false));
    for (int i = 0; i < M; i++) {
        int X, Y;
        cin >> X >> Y;
        obstacles[X-1][Y-1] = true;
    }

    vector<vector<int>> dp(N, vector<int>(N, 0));
    dp[0][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!obstacles[i][j]) {
                if (i > 0) dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
                if (j > 0) dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
            }
        }
    }

    cout << dp[N-1][N-1] << endl;

    return 0;
}