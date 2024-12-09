#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> adj;
vector<int> depth, parent;
vector<unordered_map<int, int>> ancestors;

void dfs(int u, int p, int d) {
    depth[u] = d;
    parent[u] = p;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
        }
    }
}

int find_lca(int u, int v) {
    while (depth[u] > depth[v]) {
        u = parent[u];
    }

    while (depth[v] > depth[u]) {
        v = parent[v];
    }

    while (u != v) {
        u = parent[u];
        v = parent[v];
    }

    return u;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    adj.resize(n + 1);
    depth.resize(n + 1);
    parent.resize(n + 1);
    ancestors.resize(n + 1);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, 0);

    for (int i = 0; i < m; i++) {
        int s, t;
        cin >> s >> t;
        int lca = find_lca(s, t);
        while (depth[s] > depth[lca]) {
            ancestors[s][depth[s]]++;
            s = parent[s];
        }
        while (depth[t] > depth[lca]) {
            ancestors[t][depth[t]]++;
            t = parent[t];
        }
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (auto &[depth, count] : ancestors[i]) {
            ans += count * (count - 1) / 2;
        }
    }

    cout << ans << endl;

    return 0;
}