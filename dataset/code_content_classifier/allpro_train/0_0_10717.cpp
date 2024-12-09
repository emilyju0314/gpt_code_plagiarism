#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, W;
    cin >> N >> W;

    vector<int> weights(N), values(N);
    for (int i = 0; i < N; i++) {
        cin >> weights[i] >> values[i];
    }

    vector<vector<int>> dp(N+1, vector<int>(W+1, 0));

    for (int i = 1; i <= N; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i-1] <= w) {
                dp[i][w] = max(dp[i-1][w], dp[i-1][w-weights[i-1]] + values[i-1]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    cout << dp[N][W] << endl;

    return 0;
}