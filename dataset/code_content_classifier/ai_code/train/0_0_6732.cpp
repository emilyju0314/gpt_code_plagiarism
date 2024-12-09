#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;

    long long dp[101][4][4][4];
    memset(dp, 0, sizeof(dp));

    // Initialize dp for N = 3
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                dp[3][i][j][k] = 1;
            }
        }
    }

    // Iterate for N > 3
    for (int n = 4; n <= N; ++n) {
        for (int i = 0; i < 4; ++i) { // i: n-3
            for (int j = 0; j < 4; ++j) { // j: n-2
                for (int k = 0; k < 4; ++k) { // k: n-1
                    for (int l = 0; l < 4; ++l) { // l: n
                        if (k == 0 && j == 1 && l == 2) continue; // AGC
                        if (k == 1 && j == 0 && l == 2) continue; // ACG
                        if (k == 0 && j == 2 && l == 1) continue; // GAC
                        if (k == 0 && i == 1 && l == 2) continue; // AxGC
                        if (j == 0 && i == 1 && l == 2) continue; // AxAxGC
                        dp[n][j][k][l] = (dp[n][j][k][l] + dp[n-1][i][j][k]) % MOD;
                    }
                }
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                ans = (ans + dp[N][i][j][k]) % MOD;
            }
        }
    }

    cout << ans << endl;

    return 0;
}