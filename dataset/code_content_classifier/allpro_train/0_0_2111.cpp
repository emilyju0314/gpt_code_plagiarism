#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1005;
int dp[MAXN][MAXN][1 << 10];
int board[MAXN][MAXN];
int n, m, k;

bool valid(int x, int y, int prev, int curr) {
    if (x > 0 && board[x - 1][y] == curr && (prev & (1 << curr))) return false;
    if (y > 0 && board[x][y - 1] == curr && (prev & (1 << curr))) return false;
    return true;
}

int solve(int x, int y, int prev) {
    if (x == n) return 1;
    if (y == m) return solve(x + 1, 0, prev);
    if (dp[x][y][prev] != -1) return dp[x][y][prev];

    int ans = 0;
    if (board[x][y] == 0) {
        for (int c = 1; c <= k; c++) {
            if (valid(x, y, prev, c)) {
                ans = (ans + solve(x, y + 1, prev | (1 << c))) % MOD;
            }
        }
    } else {
        if (valid(x, y, prev, board[x][y])) {
            ans = (ans + solve(x, y + 1, prev | (1 << board[x][y]))) % MOD;
        }
    }

    return dp[x][y][prev] = ans;
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    int ans = solve(0, 0, 0);
    cout << ans << endl;

    return 0;
}