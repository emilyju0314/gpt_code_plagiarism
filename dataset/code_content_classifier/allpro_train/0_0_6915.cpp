#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MOD = 100000007;

int r, c;
vector<string> grid;
int dp[11][1 << 10][301];

int dfs(int row, int colMask, int remain) {
    if (row == r) {
        return (remain == 0);
    }
    if (dp[row][colMask][remain] != -1) {
        return dp[row][colMask][remain];
    }
    
    int ans = 0;
    for (int i = 0; i < c; i++) {
        if (grid[row][i] == '.') continue;
        
        int val = grid[row][i] - '0';
        
        for (int j = 1; j <= val; j++) {
            if (j <= remain && (colMask & (1 << i)) == 0) {
                int newColMask = colMask | (1 << i);
                int newRemain = remain - j;
                ans = (ans + dfs(row + (i == c-1), newColMask, newRemain)) % MOD;
            }
        }
    }
    
    return dp[row][colMask][remain] = ans;
}

int main() {
    cin >> r >> c;
    grid.resize(r);
    for (int i = 0; i < r; i++) {
        cin >> grid[i];
    }
    
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 0, 0) << endl;
    
    return 0;
}