#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> D(N);
    for (int i = 0; i < N; i++) {
        cin >> D[i];
    }

    vector<int> C(M);
    for (int i = 0; i < M; i++) {
        cin >> C[i];
    }

    // Initialize the dp array
    vector<vector<long long>> dp(N + 1, vector<long long>(M + 1, 1e18));
    dp[0][0] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            for (int k = 0; k < i; k++) {
                if (j - (i - k - 1) >= 0) {
                    dp[i][j] = min(dp[i][j], dp[k][j - (i - k - 1)] + static_cast<long long>(D[i-1]) * C[j-1]);
                }
            }
        }
    }

    long long ans = 1e18;
    for (int j = 0; j <= M; j++) {
        ans = min(ans, dp[N][j]);
    }

    cout << ans << endl;

    return 0;
}