#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<vector<int>> dp(N+1, vector<int>(N+1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                dp[i][j] = dp[i-1][j] * 3 % MOD;
            } else {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] * (j+1)) % MOD;
            }
        }
    }

    int ans = 0;
    for (int j = 0; j <= N; j++) {
        if (A[N-1] == j) {
            ans = (ans + dp[N][j]) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}