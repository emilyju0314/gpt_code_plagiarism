#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int n, m, k;
vector<int> deg, vis, parent;
vector<int> path;
bool found = false;

void dfs(int u, int len) {
    if (found) return;
    vis[u] = 1;
    
    if (len >= n/k) {
        found = true;
        cout << "PATH\n";
        cout << len << "\n";
        for (int x : path) cout << x << " ";
        cout << "\n";
        return;
    }
    
    for (int v : adj[u]) {
        if (!vis[v]) {
            parent[v] = u;
            path.push_back(v);
            dfs(v, len+1);
            path.pop_back();
        } else if (v != parent[u] && v != u) {
            int p = u;
            vector<int> cycle;
            while (p != v) {
                cycle.push_back(p);
                p = parent[p];
            }
            cycle.push_back(v);
            cycle.push_back(u);
            cout << "CYCLES\n";
            cout << cycle.size() << "\n";
            for (int x : cycle) cout << x << " ";
            cout << "\n";
            if (--k == 0) return;
        }
        
        if (found) return;
    }
}

int main() {
    cin >> n >> m >> k;
    adj.resize(n+1);
    deg.resize(n+1, 0);
    vis.resize(n+1, 0);
    parent.resize(n+1, -1);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            path.push_back(i);
            dfs(i, 1);
            if (found) break;
            path.pop_back();
        }
    }
    
    if (!found) cout << -1 << "\n";
    
    return 0;
}