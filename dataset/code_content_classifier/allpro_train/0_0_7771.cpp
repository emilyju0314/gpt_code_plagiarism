#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
    int N, K;
    cin >> N >> K;

    // Initialize a 2D vector to store the number of ways to arrange the balls
    vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));
    
    // Base case
    dp[0][0] = 1;

    // Dynamic programming
    for (int i = 1; i <= K; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][N - j]) % MOD;
        }
    }

    // Output the results
    for (int i = 1; i <= K; i++) {
        cout << dp[i][N] << "\n";
    }

    return 0;
}