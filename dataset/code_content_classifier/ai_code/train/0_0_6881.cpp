#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MOD = 1000000007;

int n, m;
int dp[105][105][105];
string grid[105];

int add(int a, int b) {
    return (a + b) % MOD;
}

int solve(int row, int col, int mask) {
    if (dp[row][col][mask] != -1) {
        return dp[row][col][mask];
    }

    if (row == n) {
        return (mask == 0) ? 1 : 0;
    }

    int nextRow = (col == m - 1) ? row + 1 : row;
    int nextCol = (col == m - 1) ? 0 : col + 1;

    int ans = 0;
    if (grid[row][col] == '*') {
        if ((mask & 1) && (mask & (1 << 1))) {
            ans = add(ans, solve(nextRow, nextCol, (mask ^ 1) ^ (1 << 1));
        }
    } else {
        if (mask & 1) {
            ans = add(ans, solve(nextRow, nextCol, mask & ~(1 << 1));
        }
        if (mask & (1 << 1)) {
            ans = add(ans, solve(nextRow, nextCol, mask & ~1);
        }
        ans = add(ans, solve(nextRow, nextCol, mask ^ 1));
        ans = add(ans, solve(nextRow, nextCol, mask ^ (1 << 1));
    }

    return dp[row][col][mask] = ans;
}

int main() {
    memset(dp, -1, sizeof(dp));

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    cout << solve(0, 0, 3) << endl;

    return 0;
}