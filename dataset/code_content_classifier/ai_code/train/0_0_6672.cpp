#include <iostream>
#include <vector>

using namespace std;

int maxCost = 0;

void dfs(int v, int p, vector<vector<int>>& adj, vector<int>& values, int dist, int sum) {
    sum += values[v] * dist;
    maxCost = max(maxCost, sum);

    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v, adj, values, dist + 1, sum);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1, adj, values, 0, 0);

    cout << maxCost << endl;

    return 0;
}