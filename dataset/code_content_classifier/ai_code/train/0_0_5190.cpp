#include <iostream>
#include <vector>
using namespace std;

const int mod = 1000000009;

int main() {
    int R, C;
    cin >> R >> C;

    vector<vector<int>> board(R, vector<int>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
        }
    }

    vector<vector<int>> dp(R, vector<int>(1 << C));
    dp[0][0] = 1;

    for (int i = 1; i < R; i++) {
        for (int j = 0; j < (1 << C); j++) {
            for (int k = 0; k < (1 << C); k++) {
                int cnt = 0;
                for (int l = 0; l < C; l++) {
                    cnt += ((k >> l) & 1) ^ ((j >> l) & 1);
                }

                if (cnt % 2 == 0) {
                    dp[i][k] = (dp[i][k] + dp[i - 1][j]) % mod;
                }
            }
        }
    }

    int ans = 0;
    for (int j = 0; j < (1 << C); j++) {
        int cnt = 0;
        for (int k = 0; k < C; k++) {
            cnt += (j >> k) & 1;
        }

        if (cnt % 2 == 0) {
            ans = (ans + dp.back()[j]) % mod;
        }
    }

    cout << ans << endl;

    return 0;
}