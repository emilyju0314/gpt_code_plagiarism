#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> parent;

bool dfs(int v, int p) {
    visited[v] = true;
    parent[v] = p;

    for (int u : adj[v]) {
        if (!visited[u]) {
            if (dfs(u, v)) {
                return true;
            }
        } else if (u != p && u != v && parent[u] != v) {
            return true;
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    visited.resize(n + 1);
    parent.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool hasCircuits = false;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i, 0)) {
                hasCircuits = true;
                break;
            }
        }
    }

    if (hasCircuits) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}