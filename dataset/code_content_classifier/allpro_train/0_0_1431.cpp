#include <iostream>
#include <vector>

using namespace std;

int main() {
    int C, Hr, Hb, Wr, Wb;
    cin >> C >> Hr >> Hb >> Wr >> Wb;

    // Initialize a DP table
    vector<vector<long long>> dp(C/Wr + 1, vector<long long>(C/Wb + 1, 0));

    // Fill the DP table
    for (int i = 0; i <= C/Wr; i++) {
        for (int j = 0; j <= C/Wb; j++) {
            // Using i red candies and j blue candies
            long long red_joy = (long long)i * Hr;
            long long blue_joy = (long long)j * Hb;

            dp[i][j] = max(dp[i][j], max(i > 0 ? dp[i-1][j] : 0, j > 0 ? dp[i][j-1] : 0));
            if (i * Wr + j * Wb <= C) {
                dp[i][j] = max(dp[i][j], dp[max(0, i-1)][max(0, j-1)] + red_joy + blue_joy);
            }
        }
    }

    cout << dp[C/Wr][C/Wb] << endl;

    return 0;
}