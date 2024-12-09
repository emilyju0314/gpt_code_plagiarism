#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<vector<int>> tree;
vector<int> parent;
vector<int> depth;

void dfs(int node, int par, int d) {
    parent[node] = par;
    depth[node] = d;
    for (int child : tree[node]) {
        if (child != par) {
            dfs(child, node, d + 1);
        }
    }
}

int lca(int u, int v) {
    while (u != v) {
        if (depth[u] < depth[v]) {
            v = parent[v];
        } else {
            u = parent[u];
        }
    }
    return u;
}

int dist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

int main() {
    int n, m;
    cin >> n >> m;

    tree.resize(n + 1);
    parent.resize(n + 1);
    depth.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1, -1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        int d = dist(u, v);
        if (depth[u] < depth[v]) swap(u, v);
        if (depth[u] == depth[v]) {
            int p = parent[u];
            cout << fixed << setprecision(8) << d / 2.0 << endl;
        } else {
            int p = parent[v];
            cout << fixed << setprecision(8) << (d + 1) / 2.0 << endl;
        }
    }

    return 0;
}