#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v;
    char letter;
};

vector<string> strings;
vector<vector<Edge>> tree;
vector<vector<int>> parent;
vector<int> depth;

void dfs(int node, int par) {
    parent[node][0] = par;
    for (Edge& edge : tree[node]) {
        int child = edge.u == node ? edge.v : edge.u;
        if (child != par) {
            depth[child] = depth[node] + 1;
            dfs(child, node);
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int log = 1;
    while ((1 << log) <= depth[u]) log++;
    for (int i = log; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v]) {
            u = parent[u][i];
        }
    }
    if (u == v) return u;
    for (int i = log; i >= 0; i--) {
        if (parent[u][i] != -1 && parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    tree.resize(n);
    parent.resize(n, vector<int>(20, -1));
    depth.resize(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        char letter;
        cin >> u >> v >> letter;
        u--; v--;
        tree[u].push_back({u, v, letter});
        tree[v].push_back({v, u, letter});
    }

    dfs(0, -1);

    for (int i = 1; i < 20; i++) {
        for (int v = 0; v < n; v++) {
            if (parent[v][i - 1] != -1) {
                parent[v][i] = parent[parent[v][i - 1]][i - 1];
            }
        }
    }

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        strings.push_back(s);
    }

    for (int i = 0; i < q; i++) {
        int u, v, l, r;
        cin >> u >> v >> l >> r;
        u--; v--;

        int ancestor = lca(u, v);
        int count = 0;
        for (int j = l - 1; j < r; j++) {
            string str = strings[j];
            int index = 0;
            bool found = false;
            for (Edge& edge : tree[u]) {
                int child = edge.u == u ? edge.v : edge.u;
                if (depth[child] >= depth[ancestor]) {
                    if (str[index] == edge.letter) {
                        index++;
                        if (index == str.length()) {
                            found = true;
                            break;
                        }
                    }
                }
            }
            if (found) count++;
        }

        cout << count << endl;
    }

    return 0;
}