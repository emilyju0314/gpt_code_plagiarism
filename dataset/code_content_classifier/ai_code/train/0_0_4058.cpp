#include <iostream>
#include <vector>
using namespace std;

const int MOD = 10000;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> days(N + 1, 0);
    for (int i = 0; i < K; i++) {
        int ai, bi;
        cin >> ai >> bi;
        days[ai] = bi;
    }

    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(4, vector<int>(4, 0)));
    dp[0][0][0] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 3; j++) {
            for (int k = 1; k <= 3; k++) {
                for (int l = 1; l <= 3; l++) {
                    if (l != days[i] || l == j) {
                        dp[i][l][j] = (dp[i][l][j] + dp[i - 1][j][k]) % MOD;
                    }
                }
            }
        }
    }

    int total = 0;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            total = (total + dp[N][i][j]) % MOD;
        }
    }

    cout << total << endl;

    return 0;
}