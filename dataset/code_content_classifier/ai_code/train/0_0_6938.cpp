#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int n;
vector<int> dp(100005), sz(100005);
vector<vector<int>> adj(100005);

void dfs(int u, int p) {
    sz[u] = 1;
    dp[u] = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        dp[u] = (dp[u] + (1LL * sz[u] * sz[v] % MOD * dp[v] % MOD)) % MOD;
        sz[u] += sz[v];
    }
    dp[u] = (dp[u] + (1LL * sz[u] * (n - sz[u])) % MOD) % MOD;
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
    }

    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    cout << dp[1] << endl;

    return 0;
}