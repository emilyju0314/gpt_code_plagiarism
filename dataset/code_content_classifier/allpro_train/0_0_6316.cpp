#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;
const int MAXN = 105;

struct Edge {
    int to, cost;
};

int dijkstra(vector<Edge> adjacencyList[MAXN], int start, int end) {
    int dist[MAXN];
    fill(dist, dist + MAXN, INF);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) {
            continue;
        }

        for (Edge e : adjacencyList[u]) {
            int v = e.to;
            int c = e.cost;
            
            if (dist[u] + c < dist[v]) {
                dist[v] = dist[u] + c;
                pq.push({dist[v], v});
            }
        }
    }

    return dist[end];
}

int main() {
    int n;
    cin >> n;

    vector<Edge> adjacencyList[MAXN];
    
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        
        adjacencyList[u].push_back({v, w});
        adjacencyList[v].push_back({u, w});
    }

    int start, end;
    cin >> start >> end;

    int ans = dijkstra(adjacencyList, start, end);
    cout << ans << endl;
    
    return 0;
}