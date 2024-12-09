#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> S(N), T(M);
    for(int i = 0; i < N; i++) {
        cin >> S[i];
    }
    for(int i = 0; i < M; i++) {
        cin >> T[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= M; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
                if(S[i-1] == T[j-1]) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j] + dp[i][j-1]) % MOD;
                }
                dp[i][j] = (dp[i][j] + MOD) % MOD;
            }
        }
    }

    cout << dp[N][M] << endl;

    return 0;
}