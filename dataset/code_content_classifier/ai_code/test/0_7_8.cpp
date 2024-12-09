#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 100001;
const int MAXLOG = 20;

vector<int> adj[MAXN];
int parent[MAXN][MAXLOG];
int depth[MAXN];
int energy[MAXN];
int n;

void dfs(int u, int par, int dep) {
    parent[u][0] = par;
    depth[u] = dep;
    for (int v : adj[u]) {
        if (v != par) {
            dfs(v, u, dep + 1);
        }
    }
}

void preprocess() {
    for (int j = 1; j < MAXLOG; j++) {
        for (int i = 1; i <= n; i++) {
            if (parent[i][j - 1] != -1) {
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            }
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for (int i = 0; i < MAXLOG; i++) {
        if (diff & (1 << i)) {
            u = parent[u][i];
        }
    }
    if (u == v) return u;
    for (int i = MAXLOG - 1; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int find_energy(int u, int v) {
    int l = lca(u, v);
    return abs(energy[u] + energy[v] - 2 * energy[l]);
}

int main() {
    int q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> energy[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1, 0);
    preprocess();

    while (q--) {
        int type, u, v;
        cin >> type >> u >> v;
        if (type == 1) {
            energy[u] = v;
        } else {
            cout << find_energy(u, v) << endl;
        }
    }

    return 0;
}