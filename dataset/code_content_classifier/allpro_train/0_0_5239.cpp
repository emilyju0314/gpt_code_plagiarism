#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n+1, vector<int>(n+1, 0));
    vector<int> dist(n+1, -1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    // BFS for bus
    queue<int> q;
    q.push(1);
    dist[1] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] == 0 && dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    if (dist[n] == -1) {
        cout << -1 << endl;
        return 0;
    }

    // Find the maximum distance for train
    int max_time = 0;
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && dist[u] + 1 > dist[v]) {
                max_time = max(max_time, dist[u] + 1);
            }
        }
    }

    cout << max_time << endl;

    return 0;
}