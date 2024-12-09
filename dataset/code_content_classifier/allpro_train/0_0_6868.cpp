#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000009;

int main() {
    int n, h;
    cin >> n >> h;

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2*h + 1, vector<int>(5, 0)));

    for (int i = 1; i <= 4; i++) {
        dp[1][1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= min(i, h); j++) {
            for (int dir = 1; dir <= 4; dir++) {
                for (int prevDir = 1; prevDir <= 4; prevDir++) {
                    if (dir == prevDir) {
                        dp[i][j][dir] += dp[i-1][j-1][prevDir];
                    } else {
                        dp[i][j][dir] += dp[i-1][h][prevDir];
                    }
                    dp[i][j][dir] %= MOD;
                }
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= 4; i++) {
        result += dp[n][h][i];
        result %= MOD;
    }

    cout << result << endl;

    return 0;
}