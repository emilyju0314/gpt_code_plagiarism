#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int calculateDifference(vector<vector<int>> island, int W, int H) {
    vector<vector<int>> dp(H, vector<int>(W)); // dynamic programming table
    dp[0][0] = island[0][0];

    // calculate the scores for each territory
    for (int i = 1; i < H; i++) {
        dp[i][0] = dp[i-1][0] + island[i][0];
    }

    for (int j = 1; j < W; j++) {
        dp[0][j] = dp[0][j-1] + island[0][j];
    }

    for (int i = 1; i < H; i++) {
        for (int j = 1; j < W; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + island[i][j];
        }
    }

    // calculate the absolute difference between the scores of Nobuo-kun and Shizuo-kun
    return abs(dp[H-1][W-1] - dp[0][0]);
}

int main() {
    int W, H;
    cin >> W >> H;

    vector<vector<int>> island(H, vector<int>(W));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> island[i][j];
        }
    }

    int difference = calculateDifference(island, W, H);
    cout << difference << endl;

    return 0;
}