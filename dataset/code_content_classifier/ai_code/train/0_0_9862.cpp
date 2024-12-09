#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    while (true) {
        int H, W;
        cin >> H >> W;
        
        if (H == 0 && W == 0) {
            break;
        }
        
        vector<vector<int>> dp(H, vector<int>(W, 0));
        
        for (int i = 0; i < H; i++) {
            string line;
            cin >> line;
            
            for (int j = 0; j < W; j++) {
                if (line[j] == '.') {
                    dp[i][j] = 1;
                }
            }
        }
        
        for (int i = 1; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (dp[i][j] != 0) {
                    dp[i][j] += dp[i - 1][j];
                }
            }
        }
        
        int maxArea = 0;
        
        for (int i = 0; i < H; i++) {
            vector<int> stack;
            stack.push_back(-1);
            
            for (int j = 0; j < W; j++) {
                while (stack.back() != -1 && dp[i][stack.back()] >= dp[i][j]) {
                    int h = dp[i][stack.back()];
                    stack.pop_back();
                    maxArea = max(maxArea, h * (j - stack.back() - 1));
                }
                stack.push_back(j);
            }
        }
        
        cout << maxArea << endl;
    }
    
    return 0;
}