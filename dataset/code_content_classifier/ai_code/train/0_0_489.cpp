#include <iostream>
#include <vector>
#define MOD 998244353

using namespace std;

int main() {
    int N, S;
    cin >> N >> S;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<vector<int>> dp(N+1, vector<int>(S+1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= S; j++) {
            dp[i][j] = (2 * dp[i-1][j]) % MOD;
            if (j - A[i-1] >= 0) {
                dp[i][j] = (dp[i][j] + dp[i-1][j - A[i-1]]) % MOD;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = (ans + dp[i][S]) % MOD;
    }

    cout << ans << endl;

    return 0;
}