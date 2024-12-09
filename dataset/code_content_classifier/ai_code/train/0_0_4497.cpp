#include <iostream>
#include <vector>
#include <cstring>
#define MOD 1000000007

using namespace std;

int H, W;
char dungeon[505][20];
bool visited[505][20];
int dp[505][20][1 << 15];

int solve(int row, int col, int mask) {
    if (row == H) {
        return mask == 0 ? 1 : 0;
    }
    
    if (col == W) {
        return solve(row + 1, 0, mask);
    }
    
    if (visited[row][col] || dungeon[row][col] == '#') {
        return solve(row, col + 1, mask);
    }
    
    if (dp[row][col][mask] != -1) {
        return dp[row][col][mask];
    }
    
    visited[row][col] = true;
    
    int ways = 0;
    
    if ((mask & (1 << col)) == 0) {
        ways += solve(row, col + 1, mask | (1 << col));
        ways %= MOD;
    }
    
    if (col + 1 < W && (mask & (1 << col)) == 0 && (mask & (1 << (col + 1))) == 0) {
        ways += solve(row, col + 2, mask);
        ways %= MOD;
    }
    
    ways += solve(row, col + 1, mask);
    ways %= MOD;
    
    visited[row][col] = false;
    
    return dp[row][col][mask] = ways;
}

int main() {
    int caseNum = 1;
    
    while (cin >> H >> W && H != 0 && W != 0) {
        memset(visited, false, sizeof(visited));
        memset(dp, -1, sizeof(dp));
        
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> dungeon[i][j];
            }
        }
        
        int ways = solve(0, 0, 0);
        
        cout << "Case " << caseNum++ << ": " << ways << endl;
    }
    
    return 0;
}