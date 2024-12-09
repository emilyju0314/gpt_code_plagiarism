#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> a;
vector<vector<int>> adj;
vector<int> parent;
vector<int> depth;

void dfs(int u, int p, int d) {
    parent[u] = p;
    depth[u] = d;
    for(int v : adj[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    a.resize(n);
    adj.resize(n);
    parent.resize(n);
    depth.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1, 0);

    for (int i = 0; i < q; i++) {
        int type, u, v;
        cin >> type >> u >> v;
        u--; v--;

        if (type == 1) {
            a[u] = v;
        } else {
            int energy = 0;
            while (u != v) {
                int u_ = a[u], v_ = a[v];
                energy += max(abs(u_ + v_), abs(u_ - v_));
                if (depth[u] > depth[v]) {
                    u = parent[u];
                } else {
                    v = parent[v];
                }
            }
            cout << energy << endl;
        }
    }

    return 0;
}