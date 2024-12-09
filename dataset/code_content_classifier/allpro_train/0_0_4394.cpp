#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K, R, S, P;
    cin >> N >> K >> R >> S >> P;
    string T;
    cin >> T;

    vector<int> dp(N, 0);
    for (int i = 0; i < K; i++) {
        if (T[i] == 'r') dp[i] = P;
        if (T[i] == 's') dp[i] = R;
        if (T[i] == 'p') dp[i] = S;
    }

    for (int i = K; i < N; i++) {
        if (T[i] == 'r') dp[i] = max(dp[i-K] + P, max(dp[i-K+1] + S, dp[i-K+2] + R));
        if (T[i] == 's') dp[i] = max(dp[i-K] + S, max(dp[i-K+1] + R, dp[i-K+2] + P));
        if (T[i] == 'p') dp[i] = max(dp[i-K] + R, max(dp[i-K+1] + P, dp[i-K+2] + S));
    }

    int max_score = 0;
    for (int i = 0; i < N; i++) {
        max_score += dp[i];
    }

    cout << max_score << endl;

    return 0;
}