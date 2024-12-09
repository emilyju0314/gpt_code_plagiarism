#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> adj[MAXN];
vector<int> parent(MAXN, -1);
vector<int> depth(MAXN, 0);
vector<int> weight(MAXN, 0);
vector<vector<int>> dp(MAXN, vector<int>(20, 0)); // DP table for LCA
int n, q;

void dfs(int u, int p, int d) {
    parent[u] = p;
    depth[u] = d;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, d+1);
    }
}

void preprocess() {
    for (int u = 1; u <= n; u++) {
        dp[u][0] = parent[u];
    }

    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i <= n; i++) {
            if (dp[i][j-1] != -1) {
                dp[i][j] = dp[dp[i][j-1]][j-1];
            }
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    int log;
    for (log = 1; (1 << log) <= depth[u]; log++);
    log--;

    for (int i = log; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v]) {
            u = dp[u][i];
        }
    }

    if (u == v) return u;

    for (int i = log; i >= 0; i--) {
        if (dp[u][i] != -1 && dp[u][i] != dp[v][i]) {
            u = dp[u][i];
            v = dp[v][i];
        }
    }

    return parent[u];
}

int query(int u, int v) {
    int ans = INT_MIN;
    int lcaNode = lca(u, v);
    
    while (u != lcaNode) {
        ans = max(ans, weight[u]);
        u = parent[u];
    }

    while (v != lcaNode) {
        ans = max(ans, weight[v]);
        v = parent[v];
    }

    ans = max(ans, weight[lcaNode]);

    return ans;
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> weight[i];
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1, 0);
    preprocess();

    for (int i = 0; i < q; i++) {
        int type, u, v, c;
        cin >> type >> u >> v >> c;

        if (type == 1) {
            // Process modification query
            int l = lca(u, v);
            while (u != l) {
                weight[u] = c;
                u = parent[u];
            }
            while (v != l) {
                weight[v] = c;
                v = parent[v];
            }
            weight[l] = c;
        } else {
            // Process output query
            int ans = query(u, v);
            cout << ans << endl;
        }
    }

    return 0;
}