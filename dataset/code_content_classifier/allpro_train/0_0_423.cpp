#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <climits>

using namespace std;

#define INF INT_MAX

vector<int> dijkstra(const vector<vector<pair<int, int>>>& graph, int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(graph.size(), INF);
    
    dist[start] = 0;
    pq.push({0, start});
    
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        for(auto edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            
            if(dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist;
}

int main() {
    int N, M, E, S, T, R;
    cin >> N >> M >> E >> S >> T >> R;
    
    vector<vector<pair<int, int>>> graph(N);
    
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back({v, 1});
        graph[v].push_back({u, 1});
    }
    
    for(int i = 0; i < E; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back({v, 1});
        graph[v].push_back({u, 1});
    }
    
    vector<int> dist = dijkstra(graph, S);
    
    if(dist[T] == INF) {
        cout << -1 << endl;
    } else {
        if(dist[S] < dist[T]) {
            cout << dist[T] << endl;
        } else {
            cout << dist[T] + R << endl;
        }
    }
    
    return 0;
}