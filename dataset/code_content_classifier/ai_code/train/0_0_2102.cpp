#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

struct Edge {
    int to, weight;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> adjList(n + 1);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    vector<int> dist(n + 1, INF);
    dist[1] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});

    while(!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if(d > dist[u]) continue;

        for(auto edge : adjList[u]) {
            int v = edge.to;
            int w = edge.weight;
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for(int i = 2; i <= n; i++) {
        int minPathWeight = dist[i];
        for(auto edge : adjList[i]) {
            int edgeWeight = edge.weight;
            int edgeU = i;
            int edgeV = edge.to;
            int pathWeight = dist[edgeU] + edgeWeight + dist[edgeV] - max(dist[edgeU], dist[edgeV]);
            minPathWeight = min(minPathWeight, pathWeight);
        }
        cout << minPathWeight << " ";
    }

    return 0;
}