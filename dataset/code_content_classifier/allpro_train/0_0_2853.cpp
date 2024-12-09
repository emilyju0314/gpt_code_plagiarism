#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

void dijkstra(vector<vector<pii>>& graph, vector<int>& distances, int source) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, source});
    
    distances[source] = 0;
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int u_dist = pq.top().first;
        pq.pop();
        
        if (u_dist > distances[u]) continue;
        
        for (auto neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            
            if (distances[v] > distances[u] + weight) {
                distances[v] = distances[u] + weight;
                pq.push({distances[v], v});
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<pii>> graph(n);
    vector<int> distances(n, INT_MAX);
    
    for (int i = 0; i < n; i++) {
        int u, k;
        cin >> u >> k;
        
        for (int j = 0; j < k; j++) {
            int v, c;
            cin >> v >> c;
            
            graph[u].push_back({v, c});
        }
    }
    
    dijkstra(graph, distances, 0);
    
    for (int i = 0; i < n; i++) {
        cout << i << " " << distances[i] << endl;
    }
    
    return 0;
}