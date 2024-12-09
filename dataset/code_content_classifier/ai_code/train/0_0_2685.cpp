#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

int dfs(int v) {
    visited[v] = true;
    int res = 1;
    for (int u : adj[v]) {
        if (!visited[u]) {
            res += dfs(u);
        }
    }
    return res;
}

int main() {
    int N, Q;
    cin >> N >> Q;

    adj.resize(N + 1);
    visited.resize(N + 1, false);

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < Q; i++) {
        int t, v;
        cin >> t >> v;
        if (t == 1) {
            // Invert the color of vertex v
            // Not required for the query
        } else if (t == 2) {
            // Answer the number of vertices reachable from white vertex v
            visited.assign(N + 1, false);
            visited[v] = true;
            int ans = dfs(v) - 1; // Exclude the starting vertex
            cout << ans << endl;
        }
    }

    return 0;
}