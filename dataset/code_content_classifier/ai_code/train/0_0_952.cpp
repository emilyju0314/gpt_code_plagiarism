#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int h, w, W;
    cin >> h >> w >> W;

    vector<vector<int>> grid(h, vector<int>(w));
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dp(h, vector<int>(w, 0));
    for(int i = 1; i < h; i++) {
        for(int j = 1; j < w; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
    }

    int maxIncome = 0;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            maxIncome = max(maxIncome, dp[i][j]);
        }
    }

    int totalIncome = 0;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            totalIncome += maxIncome - grid[i][j];
        }
    }

    int totalElectricityBill = maxIncome * W;

    cout << totalIncome - totalElectricityBill << endl;

    return 0;
}