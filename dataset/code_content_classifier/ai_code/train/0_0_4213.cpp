#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

struct Edge {
    int to, weight;
};

int V, E, N, K;
vector<int> start_city;
vector<vector<Edge>> adj_list;

vector<vector<int>> dijkstra(int start) {
    vector<vector<int>> dist(N, vector<int>(V+1, INF));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;
    pq.push({0, {start, 0}});
    
    while (!pq.empty()) {
        int cost = pq.top().first;
        int city = pq.top().second.first;
        int unique_cities = pq.top().second.second;
        pq.pop();
        
        if (dist[city][unique_cities] != INF) {
            continue;
        }
        
        dist[city][unique_cities] = cost;
        
        for (Edge e : adj_list[city]) {
            int new_cost = cost + e.weight;
            int new_unique_cities = unique_cities + (start_city[city] != start_city[e.to]);
            
            if (new_unique_cities <= K && new_cost < dist[e.to][new_unique_cities]) {
                pq.push({new_cost, {e.to, new_unique_cities}});
            }
        }
    }
    
    return dist;
}

int main() {
    cin >> V >> E >> N >> K;
    
    start_city.resize(V);
    for (int i = 0; i < N; i++) {
        int city;
        cin >> city;
        start_city[city-1]++;
    }
    
    adj_list.resize(V);
    for (int i = 0; i < E; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        adj_list[a-1].push_back({b-1, t});
        adj_list[b-1].push_back({a-1, t});
    }
    
    vector<vector<vector<int>>> dist(N);
    for (int i = 0; i < N; i++) {
        dist[i] = dijkstra(i);
    }
    
    int ans = INF;
    for (int t = 1; t <= 600*N; t++) {
        int min_time = 0;
        for (int i = 0; i < V; i++) {
            int min_dist = INF;
            for (int j = 0; j < N; j++) {
                min_dist = min(min_dist, dist[j][i][K-1]);
            }
            min_time = max(min_time, min_dist);
        }
        
        if (min_time <= t) {
            ans = t;
            break;
        }
    }
    
    if (ans != INF) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}