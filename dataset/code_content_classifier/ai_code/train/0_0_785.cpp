#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int MAXK = 105;

vector<pair<int, int>> adj[MAXN]; // adjacency list
int dp[MAXN][MAXK]; // dp table
int n, k;

void dfs(int u, int p) {
    dp[u][0] = 1;
    for (auto& [v, color] : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        for (int j = 0; j < k; j++) {
            if (color == 1) {
                dp[u][j + 1] += dp[v][j];
            } else {
                dp[u][j + 1] += dp[v][j];
                dp[u][j + 1] %= MOD;
                dp[u][j + 1] += 1LL * dp[v][j] * (k - 1) % MOD;
                dp[u][j + 1] %= MOD;
            }
        }
    }
}

int main() {
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        adj[u].emplace_back(v, x);
        adj[v].emplace_back(u, x);
    }

    dfs(1, -1);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + dp[i][1]) % MOD;
    }

    cout << ans << endl;

    return 0;
}