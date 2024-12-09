#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N), B(M);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    vector<vector<int>> dp(N+1, vector<int>(M+1, 0));
    dp[0][0] = 1;

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            if (i < N && A[i] <= B[j]) {
                dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % MOD;
            }
            if (j < M && A[i] >= B[j]) {
                dp[i][j+1] = (dp[i][j+1] + dp[i][j]) % MOD;
            }
        }
    }

    cout << dp[N][M] << endl;

    return 0;
}