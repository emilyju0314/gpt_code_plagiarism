#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfs(int start, vector<vector<int>>& adj) {
    vector<int> distances(adj.size(), -1);
    queue<int> q;
    q.push(start);
    distances[start] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (distances[neighbor] == -1) {
                q.push(neighbor);
                distances[neighbor] = distances[node] + 1;
            }
        }
    }

    return distances;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int t;
    cin >> t;

    vector<int> distances = bfs(1, adj);

    while (t--) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;

        int res = min(distances[u] + distances[v] + 1, min(distances[x] + distances[y] + 1, (distances[u] + distances[x] + 1 + distances[v] + distances[y] + 1) / 2));
        cout << (res >= distances[1] ? -1 : res) << endl;
    }

    return 0;
}