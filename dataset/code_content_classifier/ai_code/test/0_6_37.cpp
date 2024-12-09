#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> parent;
vector<bool> visited;

int find(int u) {
    return parent[u] == u ? u : parent[u] = find(parent[u]);
}

void unionSets(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    if (pu != pv) {
        parent[pu] = pv;
    }
}

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            cout << u+1 << " " << v+1 << endl;
            dfs(v);
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        adj.resize(n);
        parent.resize(n);
        visited.assign(n, false);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            a--;
            b--;
            c--;
            adj[a].push_back(b);
            adj[b].push_back(a);
            unionSets(a, c);
        }

        vector<int> roots;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) {
                roots.push_back(i);
            }
        }

        int root = roots[0];
        for (int i = 1; i < roots.size(); i++) {
            cout << root+1 << " " << roots[i]+1 << endl;
            parent[roots[i]] = root;
        }

        dfs(root);

        adj.clear();
        parent.clear();
    }

    return 0;
}