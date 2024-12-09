#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;
vector<vector<int>> adj;
vector<int> dist;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, a, b, da, db;
        cin >> n >> a >> b >> da >> db;

        adj.assign(n + 1, vector<int>());
        dist.assign(n + 1, INF);

        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bfs(a);

        if (dist[b] <= da) {
            cout << "Alice" << endl;
            continue;
        }

        int max_distance = 0;
        int farthest_node = 0;

        for (int i = 1; i <= n; i++) {
            if (dist[i] > max_distance) {
                max_distance = dist[i];
                farthest_node = i;
            }
        }

        dist.assign(n + 1, INF);
        bfs(farthest_node);
        
        if (2 * da >= db || dist[b] <= 2 * da) {
            cout << "Alice" << endl;
        } else {
            cout << "Bob" << endl;
        }
    }

    return 0;
}