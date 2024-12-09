#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

struct Edge {
    int to;
    int weight;
};

vector<vector<Edge>> graph;

vector<int> dijkstra(int start) {
    vector<int> dist(graph.size(), INF);
    dist[start] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {distance, vertex}
    pq.push({0, start});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (Edge& e : graph[u]) {
            int v = e.to;
            int w = e.weight;
            
            if (d + w < dist[v]) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist;
}

int main() {
    int N, M, L;
    
    while (cin >> N >> M >> L) {
        if (N == 0 && M == 0 && L == 0) break;
        
        graph.clear();
        graph.resize(N);
        
        for (int i = 0; i < M; i++) {
            int u, v, d;
            cin >> u >> v >> d;
            graph[u].push_back({v, d});
            graph[v].push_back({u, d});
        }
        
        vector<int> dist;
        vector<pair<int, int>> requests;
        
        for (int i = 0; i < L; i++) {
            int p, t;
            cin >> p >> t;
            requests.push_back({p, t});
        }
        
        int ans = 0;
        
        for (int i = 0; i < L; i++) {
            dist = dijkstra(requests[i].first);
            int time = dist[0] + requests[i].second;
            
            for (int j = 1; j < N; j++) {
                time = max(time, dist[j] + requests[i].second);
            }
            
            ans = max(ans, time);
        }
        
        cout << (ans + 1) << endl;
    }
    
    return 0;
}