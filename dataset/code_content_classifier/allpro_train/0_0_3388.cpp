#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MOD = 1e9 + 7;

vector<vector<int>> adj;
vector<int> size, depth, dp, dp2;

int dfs(int v, int p) {
    size[v] = 1;
    for (int u : adj[v]) {
        if (u != p) {
            depth[u] = depth[v] + 1;
            size[v] += dfs(u, v);
        }
    }
    return size[v];
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n+1);
    size.resize(n+1);
    depth.resize(n+1);
    dp.resize(n+1);
    dp2.resize(n+1);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    dp2[1] = 1;
    for (int u : adj[1]) {
        dp[1] += dfs(u, 1) * (dfs(u, 1) - 1) / 2;
        dp2[1] += dp2[u];
    }

    for (int u : adj[1]) {
        dfs(u, 1);
        dp[u] = dp[1] - size[u] * (size[u] - 1) / 2;
        dp2[u] = dp2[1] - dp2[u];
    }

    long long result = 0;
    for (int i = 1; i <= n; i++) {
        result = (result + 1LL * dp[i] * (n - size[i]) % MOD * size[i]) % MOD;
        result = (result + 1LL * dp2[i] * (n - size[i])) % MOD;
    }

    long long inv = pow(2, MOD - 2, MOD);
    result = result * inv % MOD;
    
    cout << result << endl;

    return 0;
}