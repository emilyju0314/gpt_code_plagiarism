#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int N, int W, vector<int>& values, vector<int>& weights) {
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[N][W];
}

int main() {
    int N, W;
    cin >> N >> W;

    vector<int> values(N);
    vector<int> weights(N);

    for (int i = 0; i < N; i++) {
        cin >> values[i] >> weights[i];
    }

    int result = knapsack(N, W, values, weights);
    cout << result << endl;

    return 0;
}