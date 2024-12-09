#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int R, C, K;
    cin >> R >> C >> K;
    
    vector<vector<int>> items(R, vector<int>(C, 0));
    
    for(int i = 0; i < K; i++) {
        int r, c, v;
        cin >> r >> c >> v;
        items[r-1][c-1] = v;
    }
    
    vector<vector<vector<int>>> dp(R, vector<vector<int>>(C, vector<int>(4, 0)));
    
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            for(int k = 0; k < 4; k++) {
                dp[i][j][k] = max(dp[i][j][k], (i > 0) ? dp[i-1][j][3] : 0);
                dp[i][j][1] = max(dp[i][j][1], (j > 0) ? dp[i][j-1][k] + items[i][j] : items[i][j]);
                dp[i][j][k] = max(dp[i][j][k], (j > 0) ? dp[i][j-1][k] : 0);
                
                if(k < 3) {
                    dp[i][j][k+1] = max(dp[i][j][k+1], dp[i][j][k] + items[i][j]);
                }
            }
        }
    }
    
    int ans = 0;
    for(int k = 0; k < 4; k++) {
        ans = max(ans, dp[R-1][C-1][k]);
    }

    cout << ans << endl;
    
    return 0;
}