#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int k;
    cin >> k;

    // Number of colors
    int colors = 6;

    // Initialize dp array to store the number of good colorings
    vector<vector<long long>> dp(k + 1, vector<long long>(colors, 0));

    // Base case
    for (int i = 0; i < colors; i++) {
        dp[1][i] = 1;
    }

    // Fill in the dp array
    for (int i = 2; i <= k; i++) {
        dp[i][0] = (dp[i-1][1] + dp[i-1][2] + dp[i-1][3] + dp[i-1][4] + dp[i-1][5]) % MOD;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2] + dp[i-1][4] + dp[i-1][5]) % MOD;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][3] + dp[i-1][5]) % MOD;
        dp[i][3] = (dp[i-1][0] + dp[i-1][2] + dp[i-1][4] + dp[i-1][5]) % MOD;
        dp[i][4] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][3] + dp[i-1][5]) % MOD;
        dp[i][5] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2] + dp[i-1][3]) % MOD;
    }

    // Calculate the total number of good colorings by summing up the last level
    long long total = 0;
    for (int i = 0; i < colors; i++) {
        total = (total + dp[k][i]) % MOD;
    }

    cout << total << endl;

    return 0;
}