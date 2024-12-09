#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<pair<int, int>> edges(m);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges[i] = {u, v};
    }

    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
    vector<vector<int>> parent(n + 1, vector<int>(n + 1, -1));

    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
        queue<int> q;
        q.push(i);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (dist[i][v] == INF) {
                    dist[i][v] = dist[i][u] + 1;
                    parent[i][v] = u;
                    q.push(v);
                }
            }
        }
    }

    int min_length = INF;
    vector<int> bob_route, alex_route;

    for (auto [u, v] : edges) {
        if (dist[1][n] == dist[1][u] + dist[v][n] + 1) {
            int curr_length = dist[1][u] + dist[v][n] + 1;
            if (curr_length < min_length) {
                min_length = curr_length;
                bob_route.clear();
                alex_route.clear();

                int curr = v;
                while (curr != -1) {
                    bob_route.push_back(curr);
                    curr = parent[u][curr];
                }
                reverse(bob_route.begin(), bob_route.end());

                curr = u;
                while (curr != -1) {
                    alex_route.push_back(curr);
                    curr = parent[v][curr];
                }
                alex_route.push_back(n);
            }
        }
    }

    if (min_length == INF) {
        cout << -1 << endl;
    } else {
        cout << min_length << endl;
        for (int crossroad : bob_route) {
            cout << crossroad << " ";
        }
        cout << endl;
        for (int crossroad : alex_route) {
            cout << crossroad << " ";
        }
        cout << endl;
    }

    return 0;
}