#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int n;
vector<vector<int>> adj;
vector<int> values;
vector<int> parent;
vector<vector<int>> dp;

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

void dfs(int u, int par) {
    parent[u] = par;
    dp[u][0] = gcd(values[u], values[par]);
    for (int i = 1; i < 20; i++) {
        dp[u][i] = gcd(dp[u][i - 1], dp[parent[u]][i - 1]);
    }
    for (int v : adj[u]) {
        if (v != par) {
            dfs(v, u);
        }
    }
}

int query(int u, int v, int x) {
    int ans = 1;
    while (u != v) {
        int l = log2(u ^ v);
        if (dp[v][l] % x != 0)
            ans = (1LL * ans * (dp[v][l] % x)) % MOD;
        v = parent[v];
    }
    if (dp[u][0] % x != 0)
        ans = (1LL * ans * (dp[u][0] % x)) % MOD;
    return ans;
}

int main() {
    cin >> n;
    adj.resize(n + 1);
    parent.resize(n + 1);
    values.resize(n + 1);
    dp.assign(n + 1, vector<int>(20));

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        cin >> values[i];
    }

    dfs(1, 0);

    int q;
    cin >> q;

    while (q--) {
        int u, v, x;
        cin >> u >> v >> x;
        cout << query(u, v, x) << endl;
    }

    return 0;
}