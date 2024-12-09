#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9;

int dp[100005][105];

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> adj(n + 1, vector<int>());

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (int j = 1; j <= 100; j++) {
        for (int i = 1; i <= n; i++) {
            dp[i][j] = dp[i-1][j];
            for (int v : adj[i]) {
                dp[i][j] = (dp[i][j] + dp[v-1][j-1]) % MOD;
            }
        }
    }

    int ans = dp[n][n-1];
    cout << ans << endl;

    return 0;
}