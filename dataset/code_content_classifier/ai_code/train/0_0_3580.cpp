#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

int bfs(vector<int> adj[], int src, int dest, int V) {
    bool visited[V] = {false};
    visited[src] = true;
    queue<int> q;
    q.push(src);
    int level = 0;

    while (!q.empty()) {
        int size = q.size();
        level++;
        for (int i = 0; i < size; i++) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (v == dest) {
                    return level;
                }
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }
    return -1;
}

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<int> adj[n+1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }

    int k;
    cin >> k;
    int buses[k][2];
    for (int i = 0; i < k; i++) {
        cin >> buses[i][0] >> buses[i][1];
    }

    if (bfs(adj, a, b, n) == -1) {
        cout << -1 << endl;
        return 0;
    }

    int min_buses = INT_MAX;
    for (int i = 0; i < k; i++) {
        int result = max(bfs(adj, buses[i][0], a, n), bfs(adj, b, buses[i][1], n));
        min_buses = min(min_buses, result);
    }

    cout << min_buses << endl;

    return 0;
}