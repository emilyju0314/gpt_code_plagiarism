#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> dist(n, -1);
    queue<int> q;
    q.push(0);
    dist[0] = 0;

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
    for (int i = 0; i < n; ++i) {
        max_dist = max(max_dist, dist[i]);
    }

    cout << 2 * max_dist << endl;

    return 0;
}