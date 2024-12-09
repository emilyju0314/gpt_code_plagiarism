#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<char>> grid(H, vector<char>(W));
    vector<vector<int>> dp(H, vector<int>(W, 0));
    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j];
        }
    }

    dp[0][0] = 1;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == '#') continue;
            if (i + 1 < H && grid[i + 1][j] == '.') {
                dp[i + 1][j] += dp[i][j];
                dp[i + 1][j] %= MOD;
            }
            if (j + 1 < W && grid[i][j + 1] == '.') {
                dp[i][j + 1] += dp[i][j];
                dp[i][j + 1] %= MOD;
            }
        }
    }

    cout << dp[H-1][W-1] << endl;

    return 0;
}