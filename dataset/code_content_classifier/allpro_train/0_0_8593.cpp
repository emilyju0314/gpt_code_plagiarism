#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adj[200001];
vector<bool> visited;

long long int dfs(int v, int p) {
    visited[v] = true;
    long long int count = 1;
    for (int u : adj[v]) {
        if (u != p && !visited[u]) {
            count += dfs(u, v);
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }

        for (int i = 0; i < n; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        visited.assign(n + 1, false);

        long long int totalPaths = dfs(1, -1);

        cout << totalPaths * (totalPaths-1) / 2 << endl;
    }

    return 0;
}