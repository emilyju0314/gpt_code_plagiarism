#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct Edge {
    int v, c;
};

vector<vector<Edge>> adj;
vector<int> dist, parent;

bool dijkstra(int s, int t) {
    dist.assign(adj.size(), INT_MAX);
    parent.assign(adj.size(), -1);
    dist[s] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({dist[s], s});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        if (u == t) {
            return true;
        }
        
        if (d > dist[u]) {
            continue;
        }
        
        for (Edge e: adj[u]) {
            if (dist[e.v] > dist[u] + e.c) {
                dist[e.v] = dist[u] + e.c;
                parent[e.v] = u;
                pq.push({dist[e.v], e.v});
            }
        }
    }
    
    return false;
}

int main() {
    int n;
    cin >> n;
    
    while (n--) {
        int N, M;
        cin >> N >> M;
        
        adj.assign(N, {});
        
        for (int i = 0; i < M; ++i) {
            int u, v, c;
            cin >> u >> v >> c;
            adj[u].push_back({v, c});
        }
        
        int s, t;
        cin >> s >> t;
        
        if (!dijkstra(s, t)) {
            cout << "unreachable\n";
        } else {
            cout << dist[t] << endl;
        }
    }
    
    return 0;
}
