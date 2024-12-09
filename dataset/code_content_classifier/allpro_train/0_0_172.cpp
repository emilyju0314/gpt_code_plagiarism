#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define pii pair<int, int>

const int INF = INT_MAX;

void dijkstra(int src, vector<vector<pii>> &adjList, vector<int> &dist) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[src] = 0;
    pq.push(make_pair(0, src));

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto neighbor : adjList[u]) {
            int v = neighbor.first;
            int w = neighbor.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> specialVertices(k);
    for (int i = 0; i < k; i++) {
        cin >> specialVertices[i];
        specialVertices[i]--;
    }

    vector<vector<pii>> adjList(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adjList[u].push_back(make_pair(v, w));
        adjList[v].push_back(make_pair(u, w));
    }

    vector<vector<int>> distances(k, vector<int>(k, -1));
    for (int i = 0; i < k; i++) {
        vector<int> dist(n, INF);
        dijkstra(specialVertices[i], adjList, dist);
        for (int j = 0; j < k; j++) {
            distances[i][j] = dist[specialVertices[j]];
        }
    }

    for (int i = 0; i < k; i++) {
        int maxDistance = 0;
        for (int j = 0; j < k; j++) {
            maxDistance = max(maxDistance, distances[i][j]);
        }
        cout << maxDistance << " ";
    }
    cout << endl;

    return 0;
}