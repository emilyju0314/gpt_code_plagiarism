#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

int main() {
    int H, W, A, B;
    cin >> H >> W >> A >> B;

    vector<vector<int>> dp(H, vector<int>(W, 0));
    dp[0][0] = 1;

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(i < A && j < B) continue; // Forbidden cells
            if(i > 0) dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            if(j > 0) dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
        }
    }

    cout << dp[H-1][W-1] << endl;

    return 0;
}