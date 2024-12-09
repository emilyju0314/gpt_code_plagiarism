#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<int>> tree;
vector<int> parent;
vector<int> depth;

void dfs(int node, int d) {
    depth[node] = d;
    for (int child : tree[node]) {
        dfs(child, d+1);
    }
}

int lca(int u, int v) {
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
    int n;
    cin >> n;
    
    tree.resize(n);
    parent.resize(n, -1);
    depth.resize(n);
    
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int c;
            cin >> c;
            tree[i].push_back(c);
            parent[c] = i;
        }
    }
    
    dfs(0, 0);
    
    int q;
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << endl;
    }
    
    return 0;
}