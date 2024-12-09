#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

struct Edge {
    int to, cost;
};

void dijkstra(int start, vector<vector<Edge>>& adj, vector<vector<int>>& dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start][start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        if (d > dist[start][u]) continue;
        
        for (Edge& e : adj[u]) {
            if (dist[start][u] + e.cost < dist[start][e.to]) {
                dist[start][e.to] = dist[start][u] + e.cost;
                pq.push({dist[start][e.to], e.to});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<Edge>> adj(n+1);
    vector<vector<int>> dist(n+1, vector<int>(n+1, INF));
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    for (int i = 1; i <= n; i++) {
        dijkstra(i, adj, dist);
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            int count = 0;
            for (int k = 1; k <= n; k++) {
                if (dist[i][k] + dist[k][j] == dist[i][j]) {
                    count++;
                }
            }
            cout << count << " ";
        }
    }
    
    return 0;
}