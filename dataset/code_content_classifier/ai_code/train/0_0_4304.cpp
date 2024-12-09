#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> a, b, leaf_cost;

void dfs(int node, int parent) {
    if (adj[node].size() == 1 && node != 1) {
        leaf_cost[node] = 0;
        return;
    }

    int min_cost = 1e9;
    for (int child : adj[node]) {
        if (child != parent) {
            dfs(child, node);
            min_cost = min(min_cost, a[node-1] * b[child-1]);
        }
    }

    leaf_cost[node] = min_cost;
}

int main() {
    int n;
    cin >> n;

    a.resize(n);
    b.resize(n);
    leaf_cost.resize(n);
    adj.resize(n+1);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);

    for (int i = 1; i <= n; i++) {
        cout << leaf_cost[i] << " ";
    }

    return 0;
}