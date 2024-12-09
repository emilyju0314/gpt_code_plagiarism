#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int n, m;

vector<vector<int>> adj;
vector<int> parent;
vector<int> depth;

void dfs(int node, int par, int d) {
    parent[node] = par;
    depth[node] = d;
    
    for(int neighbor : adj[node]) {
        if (neighbor != par) {
            dfs(neighbor, node, d + 1);
        }
    }
}

int findLCA(int u, int v) {
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
    cin >> n;
    adj.resize(n);
    parent.resize(n);
    depth.resize(n);
    
    for(int i = 1; i < n; i++) {
        int p;
        cin >> p;
        adj[p-1].push_back(i);
    }
    
    dfs(0, -1, 0);
    
    cin >> m;
    unordered_map<int, vector<int>> busRoutes;
    
    while (m--) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        busRoutes[a].push_back(b);
        busRoutes[b].push_back(a);
    }
    
    int q;
    cin >> q;
    
    while (q--) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        
        int lca = findLCA(u, v);
        
        if (busRoutes.count(u) && busRoutes.count(v) && busRoutes[u][0] == v) {
            cout << 1 << endl;
        } else if (lca == u || lca == v) {
            cout << depth[u] + depth[v] - 2 * depth[lca] << endl;
        } else {
            cout << -1 << endl;
        }
    }
    
    return 0;
}