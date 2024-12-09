#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> children;
vector<bool> visited;

void dfs(int v, int parent) {
    children[v] = 1; // Vertex itself
    for (int u : adj[v]) {
        if (u != parent) {
            dfs(u, v);
            children[v] += children[u];
        }
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n + 1);
    children.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 0); // Root the tree at vertex 1

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int v, k;
        cin >> v >> k;

        int max_score = max(children[v] - k, 0);
        cout << max_score << endl;
    }

    return 0;
}