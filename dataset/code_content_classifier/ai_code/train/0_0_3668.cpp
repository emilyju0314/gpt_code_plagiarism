#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    vector<vector<int>> times(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        times[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> times[i][j];
        }
    }

    vector<int> dist(n, INF);
    dist[0] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            int time = d + w;
            if (find(times[v].begin(), times[v].end(), time) != times[v].end()) {
                time++;
            }
            if (dist[v] > time) {
                dist[v] = time;
                pq.push({time, v});
            }
        }
    }

    if (dist[n-1] == INF) {
        cout << -1 << endl;
    } else {
        cout << dist[n-1] << endl;
    }

    return 0;
}