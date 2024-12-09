#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<pii>> adj(n+1);
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    vector<int> dist(n+1, INT_MAX);
    vector<bool> visited(n+1, false);
    
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1}); // (distance, city)
    dist[1] = 0;
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        if (visited[u]) continue;
        visited[u] = true;
        
        for (pii edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            
            if (dist[v] > dist[u] + w*w) {
                dist[v] = dist[u] + w*w;
                pq.push({dist[v], v});
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) {
            cout << "-1 ";
        } else {
            cout << dist[i] << " ";
        }
    }
    
    return 0;
}