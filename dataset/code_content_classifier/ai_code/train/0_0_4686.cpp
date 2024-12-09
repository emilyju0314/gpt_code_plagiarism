#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<vector<int>>& adj, int u, int p) {
    int cnt = 0;
    for (int v : adj[u]) {
        if (v != p) {
            cnt += dfs(adj, v, u);
        }
    }
    return cnt == 0 ? 1 : cnt - 1;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (dfs(adj, 0, -1) <= 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}