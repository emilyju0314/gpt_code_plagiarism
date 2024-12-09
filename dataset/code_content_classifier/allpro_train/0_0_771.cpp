#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
    int N, W;
    cin >> N >> W;

    vector<int> weights(N);
    for (int i = 0; i < N; i++) {
        cin >> weights[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
    dp[0][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i + 1][w] += dp[i][w];
            dp[i + 1][w] %= MOD;
            if (w + weights[i] <= W) {
                dp[i + 1][w + weights[i]] += dp[i][w];
                dp[i + 1][w + weights[i]] %= MOD;
            }
        }
    }

    int total = 0;
    for (int w = 0; w <= W; w++) {
        total += dp[N][w];
        total %= MOD;
    }

    cout << total << endl;

    return 0;
}