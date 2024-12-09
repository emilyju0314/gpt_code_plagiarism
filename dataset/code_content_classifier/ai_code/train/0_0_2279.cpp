#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int n;
vector<vector<int>> adj;
vector<long long> dp, sz, inv;

long long modpow(long long base, long long exp) {
    long long result = 1;
    while(exp > 0) {
        if(exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

void dfs(int u, int par) {
    sz[u] = 1;
    dp[u] = 1;

    for(int v : adj[u]) {
        if(v == par) continue;
        dfs(v, u);
        dp[u] *= sz[v];
        dp[u] %= MOD;
        dp[u] *= inv[sz[v]];
        dp[u] %= MOD;
        dp[u] *= dp[v];
        dp[u] %= MOD;
        sz[u] += sz[v];
    }
    dp[u] *= inv[sz[u]];
    dp[u] %= MOD;
}

int main() {
    cin >> n;
    adj.resize(n + 1);
    dp.resize(n + 1);
    sz.resize(n + 1);
    inv.resize(n + 1);

    for(int i = 1; i <= n; i++) {
        inv[i] = modpow(i, MOD - 2);
    }

    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    long long ans = 0;
    for(int root = 1; root <= n; root++) {
        dfs(root, 0);
        ans += dp[root];
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}