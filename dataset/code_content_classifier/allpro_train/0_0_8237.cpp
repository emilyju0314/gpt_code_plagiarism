#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int n, m, k;
vector<vector<pair<int, int>>> adj; // Adjacency list of the graph
vector<vector<int>> dist; // 2D array to store shortest path distances

int findKthSmallestPath() {
    vector<int> allDistances;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            allDistances.push_back(dist[i][j]);
        }
    }

    sort(allDistances.begin(), allDistances.end());

    return allDistances[k - 1]; // k-th smallest path is at index k - 1
}

void dijkstra(int source) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> d(n + 1, INF);

    pq.push({0, source});
    d[source] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int curDist = pq.top().first;
        pq.pop();

        if (curDist > d[u]) continue;

        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (d[u] + weight < d[v]) {
                d[v] = d[u] + weight;
                pq.push({d[v], v});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        dist[source][i] = d[i];
        dist[i][source] = d[i];
    }
}

int main() {
    cin >> n >> m >> k;

    adj.resize(n + 1);
    dist.assign(n + 1, vector<int>(n + 1, INF));

    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }

    for (int i = 1; i <= n; i++) {
        dijkstra(i);
    }

    int kthSmallestPath = findKthSmallestPath();
    cout << kthSmallestPath << endl;

    return 0;
}