#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int n, m, k;
vector<vector<int>> board;
vector<vector<vector<long long>>> dp;

long long countWays(int i, int j, int prevColor) {
    if(i == n && j == m) return 1;

    if(dp[i][j][prevColor] != -1) return dp[i][j][prevColor];

    long long ways = 0;
    int nextI = i, nextJ = j+1;
    if(nextJ > m) nextI++, nextJ = 1;

    if(board[i][j] != 0) {
        if(board[i][j] != prevColor) ways = countWays(nextI, nextJ, board[i][j]);
    } else {
        for(int color = 1; color <= k; color++) {
            if(color != prevColor) {
                board[i][j] = color;
                ways = (ways + countWays(nextI, nextJ, color)) % MOD;
                board[i][j] = 0;
            }
        }
    }

    return dp[i][j][prevColor] = ways;
}

int main() {
    cin >> n >> m >> k;
    
    board.resize(n, vector<int>(m));
    dp.resize(n+1, vector<vector<long long>>(m+1, vector<long long>(k+1, -1)));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    long long ans = countWays(0, 0, 0);
    
    cout << ans << endl;

    return 0;
}