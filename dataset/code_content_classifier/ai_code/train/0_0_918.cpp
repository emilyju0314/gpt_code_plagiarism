#include <iostream>
#include <vector>
#include <queue>

using namespace std;

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

    vector<int> dist(n, -1);
    queue<int> q;
    dist[0] = 0;
    q.push(0);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    int max_dist = 0;
    int farthest_node = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] > max_dist) {
            max_dist = dist[i];
            farthest_node = i;
        }
    }

    fill(dist.begin(), dist.end(), -1);
    dist[farthest_node] = 0;
    q.push(farthest_node);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] > res) {
            res = dist[i];
        }
    }

    cout << res << endl;

    return 0;
}