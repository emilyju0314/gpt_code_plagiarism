#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int H, N, P, M, K;
    cin >> H >> N >> P >> M >> K;

    vector<bool> hits(N, false);
    for (int i = 0; i < M; i++) {
        int Ai, Bi;
        cin >> Ai >> Bi;
        if (Bi == P) hits[Ai - 1] = true;
    }

    vector<vector<double>> dp(N, vector<double>(K + 1, 0.0));
    dp[P - 1][0] = 1.0;

    for (int k = 1; k <= K; k++) {
        vector<vector<double>> new_dp(N, vector<double>(K + 1, 0.0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                new_dp[j][k] += dp[i][k - 1] / N;
            }
        }
        for (int i = 0; i < N; i++) {
            if (hits[i]) {
                for (int j = 0; j < N; j++) {
                    new_dp[j][k] += dp[i][k - 1] / N;
                }
            } else {
                new_dp[i][k] += dp[i][k - 1];
            }
        }
        dp = new_dp;
    }

    double max_prob = 0.0;
    for (int i = 0; i < N; i++) {
        max_prob = max(max_prob, dp[i][K]);
    }

    cout << fixed << setprecision(9) << max_prob << endl;

    return 0;
}