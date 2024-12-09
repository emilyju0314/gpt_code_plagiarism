#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> subtree_size;

void dfs(int v, int parent) {
    subtree_size[v] = 1;
    for(int u : adj[v]) {
        if(u != parent) {
            dfs(u, v);
            subtree_size[v] += subtree_size[u];
        }
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n + 1);
    subtree_size.resize(n + 1);

    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);

    int edge_weight = 1;
    for(int v = 1; v <= n; v++) {
        for(int u : adj[v]) {
            if(u < v) continue;
            cout << u << " " << v << " " << edge_weight << "\n";
            edge_weight += subtree_size[u] * subtree_size[v];
        }
    }

    return 0;
}