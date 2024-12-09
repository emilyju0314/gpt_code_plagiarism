#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

void dijkstra(int s, int n, vector<vector<pair<int, int>>>& graph, vector<int>& dist) {
    dist.assign(n + 1, INF);
    dist[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;
            
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back({v, 1});
    }

    int k;
    cin >> k;
    vector<int> path(k);
    for (int i = 0; i < k; i++) {
        cin >> path[i];
    }

    vector<int> dist;
    dijkstra(path[0], n, graph, dist);

    int min_rebuilds = 0, max_rebuilds = 0;
    for (int i = 0; i < k - 1; i++) {
        int u = path[i], v = path[i + 1];
        if (dist[v] != dist[u] - 1) {
            min_rebuilds++;
        }

        for (auto& edge : graph[u]) {
            int w = edge.first;
            if (w == v) {
                max_rebuilds++;
                break;
            }
        }
    }

    cout << min_rebuilds << " " << max_rebuilds << endl;

    return 0;
}