#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(A+1, vector<int>(B+1, 0)));
    dp[0][0][0] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= A; j++) {
            for (int k = 0; k <= B; k++) {
                if (j > 0) {
                    dp[i][j][k] = (dp[i][j][k] + (long long) dp[i-1][j-1][k] * (i-k)) % MOD;
                }
                if (k > 0) {
                    dp[i][j][k] = (dp[i][j][k] + (long long) dp[i-1][j][k-1] * (j+1)) % MOD;
                }
            }
        }
    }

    cout << dp[N][A][B] << endl;

    return 0;
}