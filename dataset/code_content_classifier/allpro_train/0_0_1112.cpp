#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
    int N, K;
    cin >> N >> K;

    // Initialize a 2D vector to store the values of f(a)
    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
    for (int i = 0; i <= K; i++) {
        dp[1][i] = i + 1;
    }

    // Calculate the values of f(a) using dynamic programming
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            for (int k = 0; k <= j; k++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
            }
        }
    }
    
    // Calculate the sum of f(a) over all sequences modulo 1000000007
    int sum = 0;
    for (int i = 0; i <= K; i++) {
        sum = (sum + dp[N][i]) % MOD;
    }

    cout << sum << endl;

    return 0;
}