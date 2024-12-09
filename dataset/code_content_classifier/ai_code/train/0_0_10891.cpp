#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> happiness(N, vector<int>(3));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> happiness[i][j];
        }
    }

    vector<vector<int>> dp(N, vector<int>(3, 0));
    dp[0][0] = happiness[0][0];
    dp[0][1] = happiness[0][1];
    dp[0][2] = happiness[0][2];

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (j != k) {
                    dp[i][j] = max(dp[i][j], dp[i-1][k] + happiness[i][j]);
                }
            }
        }
    }

    cout << max({dp[N-1][0], dp[N-1][1], dp[N-1][2]}) << endl;

    return 0;
}