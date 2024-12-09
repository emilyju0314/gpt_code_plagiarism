#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int C, N, M;
    cin >> C >> N >> M;

    vector<pair<int, int>> gifts(N);

    for (int i = 0; i < N; i++) {
        cin >> gifts[i].first >> gifts[i].second;
    }

    vector<vector<int>> dp(M + 1, vector<int>(C + 1, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= M; j++) {
            for (int k = C; k >= gifts[i].first; k--) {
                dp[j][k] = max(dp[j][k], dp[j - 1][k - gifts[i].first] + gifts[i].second);
            }
        }
    }

    for (int k = 1; k <= M; k++) {
        cout << dp[k][C] << endl;
    }

    return 0;
}