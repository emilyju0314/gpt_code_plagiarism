#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int main() {
    int H, W, T;
    cin >> H >> W >> T;

    vector<vector<vector<long long>>> dp(H+1, vector<vector<long long>>(W+1, vector<long long>(T+1, 0)));

    dp[1][1][0] = 1; // Base case: one way to place the robot at (1, 1) at time 0

    for (int k = 0; k <= T; k++) {
        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= W; j++) {
                if (i == H && j == W) {
                    dp[1][1][(k+1)%T] = (dp[1][1][(k+1)%T] + dp[i][j][k]) % MOD; // Move robot to (1, 1)
                } else {
                    dp[i][j+1][(k+1)%T] = (dp[i][j+1][(k+1)%T] + dp[i][j][k]) % MOD; // Move robot to (i, j+1)
                    dp[i+1][j][(k+1)%T] = (dp[i+1][j][(k+1)%T] + dp[i][j][k]) % MOD; // Move robot to (i+1, j)
                }
            }
        }
    }

    long long ans = 0;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            ans = (ans + dp[i][j][T]) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}