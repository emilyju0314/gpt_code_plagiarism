#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& adj, vector<bool>& visited, vector<int>& order, int u) {
    visited[u] = true;
    order.push_back(u+1);
    for(int v : adj[u]) {
        if(!visited[v]) {
            dfs(adj, visited, order, v);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<pair<int, int>> points(n);
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    vector<bool> visited(n, false);
    vector<int> order;
    dfs(adj, visited, order, 0);

    for(int i = 0; i < n; i++) {
        cout << order[i] << " ";
    }

    return 0;
}