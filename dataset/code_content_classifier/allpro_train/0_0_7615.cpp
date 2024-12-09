#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MOD = 1000000007;

int dp[2005][2005]; // dp[N][D]: number of ways to eat N cookies in D days

int countWays(int N, long long D, int X) {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= D; j++) {
            for (int k = 1; k <= X; k++) {
                if (i >= k && j > 1) {
                    dp[i][j] = (dp[i][j] + dp[i - k][j - 1]) % MOD;
                }
            }
        }
    }

    int ways = 0;
    for (int i = 1; i <= X; i++) {
        ways = (ways + dp[N - i][D - 1]) % MOD;
    }

    return ways;
}

int main() {
    int N, X;
    long long D;

    while (cin >> N >> D >> X) {
        if (N == 0 && D == 0 && X == 0) break;

        int ways = countWays(N, D, X);
        cout << ways << endl;
    }

    return 0;
}