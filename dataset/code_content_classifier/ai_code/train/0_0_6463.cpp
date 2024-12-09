#include <iostream>
using namespace std;

const long long MOD = 1000000007;

int main() {
    int k, pa, pb;
    cin >> k >> pa >> pb;

    // Initialize dp array
    long long dp[k+1][k+1][2];
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j][0] = dp[i][j][1] = 0;
        }
    }
    dp[0][0][0] = dp[0][0][1] = 1;

    // Fill dp array
    for (int i = 0; i < k; i++) {
        for (int j = 0; j <= i; j++) {
            for (int p = 0; p < 2; p++) {
                dp[i+1][j][p] = (dp[i+1][j][p] + dp[i][j][p] * pa) % MOD;
                dp[i+1][j+1][1] = (dp[i+1][j+1][1] + dp[i][j][p] * pb) % MOD;
            }
        }
    }

    // Calculate expected value
    long long P = 0, Q = 0;
    for (int i = 0; i <= k; i++) {
        P = (P + (long long)i * dp[k][i][1]) % MOD;
        Q = (Q + dp[k][i][1]) % MOD;
    }

    // Inverse of Q modulo MOD
    long long invQ = 1;
    for (long long e = MOD - 2; e; e >>= 1) {
        if (e & 1) invQ = invQ * Q % MOD;
        Q = Q * Q % MOD;
    }

    // Print the answer
    cout << (P * invQ) % MOD << endl;

    return 0;
}