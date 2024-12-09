#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int H, W;
    
    while (true) {
        cin >> H >> W;
        if (H == 0 && W == 0) break;
        
        vector<vector<char>> initial(H, vector<char>(W));
        vector<vector<char>> desired(H, vector<char>(W));
        
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> initial[i][j];
            }
        }
        
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> desired[i][j];
            }
        }
        
        vector<vector<double>> dp(H+1, vector<double>(W+1));
        
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                dp[i+1][j+1] = (initial[i][j] != desired[i][j]) ? 0 : 1;
            }
        }
        
        for (int i = 0; i <= H; i++) {
            for (int j = 0; j <= W; j++) {
                if (i == 0 || j == 0) continue;
                if (i == 1 && j == 1) continue;
                
                double total = i*j;
                double blackProb = (double)i/H * (double)j/W;
                double whiteProb = 1 - blackProb;
                
                double blackExpectation = (dp[i][j-1] + dp[i-1][j]) * blackProb;
                double whiteExpectation = dp[i][j] * whiteProb;
                dp[i][j] = blackExpectation + whiteExpectation;
            }
        }
        
        cout << fixed << setprecision(10) << dp[H][W] << endl;
    }
    
    return 0;
}