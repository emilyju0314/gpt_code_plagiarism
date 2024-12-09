#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAXN = 300005; // Maximum number of vertices in the tree

vector<int> adj[MAXN]; // Adjacency list to store the tree
string chars; // String to store characters at each vertex

int parent[MAXN][20]; // Parent table for LCA
int depth[MAXN]; // Depth of each vertex

void dfs(int v, int p, int d) {
    parent[v][0] = p;
    depth[v] = d;
    for (int i = 1; i < 20; i++) {
        parent[v][i] = parent[parent[v][i-1]][i-1];
    }
    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v, d+1);
        }
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    for (int i = 19; i >= 0; i--) {
        if (depth[a] - (1 << i) >= depth[b]) {
            a = parent[a][i];
        }
    }
    if (a == b) return a;
    for (int i = 19; i >= 0; i--) {
        if (parent[a][i] != parent[b][i]) {
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return parent[a][0];
}

int commonPrefix(int a, int b, int c, int d) {
    int ab_lca = lca(a, b);
    int cd_lca = lca(c, d);
    int len = 0;
    for (int i = 19; i >= 0; i--) {
        int a_parent = parent[ab_lca][i];
        int c_parent = parent[cd_lca][i];
        if (depth[a_parent] >= depth[c_parent]) {
            len += 1 << i;
            ab_lca = a_parent;
        }
        if (depth[a_parent] <= depth[c_parent]) {
            len += 1 << i;
            cd_lca = c_parent;
        }
    }
    if (chars[ab_lca] == chars[cd_lca]) len++;
    return len;
}

int main() {
    int n;
    cin >> n;
    cin >> chars;
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 1, 0);

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << commonPrefix(a, b, c, d) << endl;
    }

    return 0;
}