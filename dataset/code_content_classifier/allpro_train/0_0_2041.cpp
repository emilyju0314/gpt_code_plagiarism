#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Edge {
    int to;
    int weight;
    int index;
};

int main() {
    int n, m;
    cin >> n >> m;

    int s, t;
    cin >> s >> t;

    vector<vector<Edge>> graph(n + 1);
    vector<vector<int>> edges(n + 1, vector<int>(n + 1, numeric_limits<int>::max()));

    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x].push_back({y, w, i + 1});
        graph[y].push_back({x, w, i + 1});
        edges[x][y] = edges[y][x] = w;
    }

    vector<int> dist(n + 1, numeric_limits<int>::max());
    vector<int> parent1(n + 1, -1);
    vector<int> parent2(n + 1, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    dist[s] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (const Edge& e : graph[u]) {
            int v = e.to;
            int w = e.weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent1[v] = u;
                parent2[v] = e.index;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[t] == numeric_limits<int>::max()) {
        cout << -1 << endl;
    } else {
        int min_budget = dist[t];
        int road_count = 0;

        vector<int> removed_roads;

        for (int i = t; parent1[i] != -1; i = parent1[i]) {
            if (edges[i][parent1[i]] != numeric_limits<int>::max()) {
                road_count++;
                removed_roads.push_back(parent2[i]);
            }
        }

        cout << min_budget << endl;
        cout << road_count << endl;
        for (int road : removed_roads) {
            cout << road << " ";
        }
        cout << endl;
    }

    return 0;
}