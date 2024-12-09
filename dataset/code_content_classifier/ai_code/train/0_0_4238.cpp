#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int end;
    int distance;
    int attackers;
};

int dijkstra(vector<vector<Edge>>& graph, int N, int M, int L) {
    vector<vector<int>> dist(N+1, vector<int>(N+1, INT_MAX));
    dist[1][L] = 0;  // Starting point is 1 and initial budget is L
    
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {1, L}});  // {distance, {node, budget}}
    
    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second.first;
        int budget = pq.top().second.second;
        pq.pop();
        
        if (dist[node][budget] < d) {
            continue;
        }
        
        for (auto& edge : graph[node]) {
            int next_node = edge.end;
            int next_dist = d + edge.distance;
            int next_attackers = edge.attackers;
            
            if (budget - edge.distance >= 0 && dist[next_node][budget - edge.distance] > next_dist) {
                dist[next_node][budget - edge.distance] = next_dist;
                pq.push({next_dist, {next_node, budget - edge.distance}});
            }
        }
    }
    
    int min_attackers = INT_MAX;
    for (int i = 0; i <= L; i++) {
        min_attackers = min(min_attackers, dist[N][i]);
    }
    
    return min_attackers;
}

int main() {
    int N, M, L;
    while (cin >> N >> M >> L && N != 0 && M != 0 && L != 0) {
        vector<vector<Edge>> graph(N+1);
        
        for (int i = 0; i < M; i++) {
            int A, B, D, E;
            cin >> A >> B >> D >> E;
            graph[A].push_back({B, D, E});
            graph[B].push_back({A, D, E});
        }
        
        int min_attackers = dijkstra(graph, N, M, L);
        cout << min_attackers << endl;
    }
    
    return 0;
}