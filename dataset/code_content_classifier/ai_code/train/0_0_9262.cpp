#include <iostream>
#include <vector>

using namespace std;

int dp[301][10001];

int main() {
    int N, T;
    cin >> N >> T;

    vector<vector<int>> roads(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b, t, m, v;
        cin >> a >> b >> t >> m >> v;
        roads[a - 1].push_back(b - 1);
        roads[b - 1].push_back(a - 1);
        for (int j = T; j >= t; j--) {
            for (int k = 0; k <= m; k++) {
                dp[a - 1][j] = max(dp[a - 1][j], dp[b - 1][j - t] + k * v);
                dp[b - 1][j] = max(dp[b - 1][j], dp[a - 1][j - t] + k * v);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, dp[i][T]);
    }

    cout << ans << endl;

    return 0;
}