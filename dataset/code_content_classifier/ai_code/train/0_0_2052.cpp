#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, k, p;
    cin >> N >> k >> p;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<vector<int>> dp(k + 1, vector<int>(N + 1, 0));

    for(int i = 1; i <= N; i++) {
        dp[1][i] = dp[1][i-1] + A[i - 1];
    }

    for(int i = 2; i <= k; i++) {
        for(int j = 1; j <= N; j++) {
            int prefixSum = 0;
            dp[i][j] = INT_MIN;
            for(int l = 1; l <= min(j, p); l++) {
                prefixSum += A[j - l];
                dp[i][j] = max(dp[i][j], max(dp[i-1][j-l], dp[i-1][j-l-1]) + prefixSum);
            }
        }
    }

    cout << dp[k][N] << endl;

    return 0;
}