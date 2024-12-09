#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MOD = 1000000007;

int main() {
    int N, M, A;
    cin >> N >> M >> A;

    vector<vector<int>> dp(N + 1, vector<int>(A + 1, 0));

    // Initialize dp table
    dp[M][1] = A;
    for (int i = M + 1; i <= N; i++) {
        for (int j = 1; j <= A; j++) {
            for (int k = 1; k <= A; k++) {
                dp[i][j] = (dp[i][j] + dp[i - M][k]) % MOD;
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= A; j++) {
            res = (res + dp[i][j]) % MOD;
        }
    }

    cout << res << endl;

    return 0;
}