#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

struct Edge {
    int to, cost;
};

void dijkstra(int start, vector<vector<Edge>>& graph, vector<int>& dist, int M) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});
  
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
      
        if (d > dist[u]) continue;
      
        for (Edge e : graph[u]) {
            int v = e.to;
            int cost = e.cost;
            int new_dist = d + cost;
          
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }
  
    for (int i = 0; i < dist.size(); i++) {
        if (dist[i] <= M) {
            dist[i] = M - dist[i];
        } else {
            dist[i] = 0;
        }
    }
}

int main() {
    int N, M, L, K, A, H;
  
    while (cin >> N >> M >> L >> K >> A >> H) {
        if (N == 0 && M == 0 && L == 0 && K == 0 && A == 0 && H == 0) break;
      
        vector<vector<Edge>> graph(N);
        vector<int> freezing(L);
        vector<int> dist(N, INF);
      
        for (int i = 0; i < L; i++) {
            cin >> freezing[i];
        }
      
        for (int i = 0; i < K; i++) {
            int X, Y, T;
            cin >> X >> Y >> T;
            graph[X].push_back({Y, T});
            graph[Y].push_back({X, T});
        }
      
        dijkstra(A, graph, dist, M);

        if (dist[H] != 0) {
            cout << "Help!" << endl;
        } else {
            cout << dist[H] << endl;
        }
    }
  
    return 0;
}