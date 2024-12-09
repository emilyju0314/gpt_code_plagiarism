#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
vector<pair<int, int>> edges;
int c[N], deg[N], w[N];
bool vis[N];

void dfs(int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs(v);
            w[v] = c[v] - w[u];
            edges.push_back({u, v});
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    
    for (int i = 1; i <= n; i++) {
        if (c[i] < -deg[i] || c[i] > deg[i]) {
            cout << "NO\n";
            return 0;
        }
    }
    
    cout << "YES\n";
    dfs(1);
    
    for (auto e : edges) {
        if (e.first < e.second) {
            cout << w[e.second] << "\n";
        } else {
            cout << -w[e.first] << "\n";
        }
    }
    
    return 0;
}