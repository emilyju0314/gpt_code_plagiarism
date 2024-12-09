#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<pair<int, int>> edges(M);
    for (int i = 0; i < M; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    vector<vector<long long>> dp(N, vector<long long>(K, 0));
    dp[0][0] = 1;

    for (int i = 0; i < N; i++) {
        vector<vector<long long>> new_dp(N, vector<long long>(K, 0));
        for (auto edge : edges) {
            int u = edge.first - 1, v = edge.second - 1;
            for (int j = 0; j < K; j++) {
                new_dp[u][(j+1)%K] += dp[v][j];
                new_dp[u][(j+1)%K] %= MOD;
                new_dp[v][(j+1)%K] += dp[u][j];
                new_dp[v][(j+1)%K] %= MOD;
            }
        }
        dp = new_dp;
    }

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += dp[i][0];
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}