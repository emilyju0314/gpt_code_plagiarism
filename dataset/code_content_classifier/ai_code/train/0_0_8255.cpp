#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <map>

using namespace std;

const long long INF = LLONG_MAX / 2;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }

    int k;
    cin >> k;

    vector<int> portals(k);
    map<int, bool> isOpen;

    for (int i = 0; i < k; i++) {
        cin >> portals[i];
        isOpen[portals[i]] = false;
    }

    // Dijkstra's Algorithm to find minimum distances from starting city to all other cities
    vector<long long> dist(n+1, INF);
    dist[1] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        int u = pq.top().second;
        long long cost = pq.top().first;
        pq.pop();

        if (dist[u] < cost) {
            continue;
        }

        for (pair<int, int> edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    long long totalTime = 0;
    for (int portal : portals) {
        totalTime += dist[portal];
        isOpen[portal] = true;
    }

    vector<long long> minDistToClosestPortal(n+1, INF);
    for (int u = 1; u <= n; u++) {
        for (pair<int, int> edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (isOpen[u] && isOpen[v]) {
                continue;
            }
            minDistToClosestPortal[u] = min(minDistToClosestPortal[u], dist[u] + weight);
            minDistToClosestPortal[v] = min(minDistToClosestPortal[v], dist[v] + weight);
        }
    }

    long long minTimeToOpenAll = INF;
    for (int portal : portals) {
        minTimeToOpenAll = min(minTimeToOpenAll, totalTime - dist[portal] + minDistToClosestPortal[portal]);
    }

    cout << minTimeToOpenAll << endl;

    return 0;
}