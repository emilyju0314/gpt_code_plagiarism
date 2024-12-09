#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<int>> matrix(H, vector<int>(W));
    vector<vector<int>> dp(H, vector<int>(W, 0));

    int ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 0) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                }
                ans = max(ans, dp[i][j]);
            }
        }
    }

    cout << ans * ans << endl;

    return 0;
}