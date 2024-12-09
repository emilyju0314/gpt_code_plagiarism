#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> A(N+1);
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    vector<vector<long long>> dp(K+1, vector<long long>(N+1, 0));

    for(int i = 1; i <= N; i++) {
        dp[1][i] = i * A[i];
    }

    for(int k = 2; k <= K; k++) {
        for(int i = 1; i <= N; i++) {
            dp[k][i] = dp[k-1][i];
            for(int j = max(1, i-M); j < i; j++) {
                dp[k][i] = max(dp[k][i], dp[k-1][j] + i * A[i]);
            }
        }
    }

    long long max_score = 0;
    for(int i = 1; i <= N; i++) {
        max_score = max(max_score, dp[K][i]);
    }

    cout << max_score << endl;

    return 0;
}