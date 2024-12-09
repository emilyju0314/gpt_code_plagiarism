#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int target;
    int weight;
};

vector<int> dijkstra(vector<vector<Edge>>& graph, int source) {
    int n = graph.size();
    vector<int> dist(n, INF);
    dist[source] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    
    while (!pq.empty()) {
        int curr_dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if (curr_dist > dist[node]) continue;
        
        for (const Edge& edge : graph[node]) {
            int new_dist = curr_dist + edge.weight;
            if (new_dist < dist[edge.target]) {
                dist[edge.target] = new_dist;
                pq.push({new_dist, edge.target});
            }
        }
    }
    
    return dist;
}

int main() {
    int V, E, r;
    cin >> V >> E >> r;
    
    vector<vector<Edge>> graph(V);
    for (int i = 0; i < E; ++i) {
        int s, t, d;
        cin >> s >> t >> d;
        graph[s].push_back({t, d});
    }
    
    vector<int> shortest_paths = dijkstra(graph, r);
    
    for (int i = 0; i < V; ++i) {
        if (shortest_paths[i] == INF) {
            cout << "INF" << endl;
        } else {
            cout << shortest_paths[i] << endl;
        }
    }
    
    return 0;
}