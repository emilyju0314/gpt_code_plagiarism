#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

struct Edge {
    int to, cost, index;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    vector<vector<int>> dist(n, vector<int>(2, INF));
    vector<int> parent(n, -1);
    vector<pair<int, int>> roads;

    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--; y--;

        graph[x].push_back({y, 1, i});
        if (z == 1) {
            graph[y].push_back({x, 1, i});
        } else {
            roads.push_back({x, y});
        }
    }

    dist[0][0] = 0;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {0, -1}});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second.first;
        int p = pq.top().second.second;
        pq.pop();

        if (d > dist[u][p]) continue;

        for (Edge& e : graph[u]) {
            int v = e.to;
            int cost = e.cost;

            if (dist[u][p] + cost < dist[v][p]) {
                dist[v][p] = dist[u][p] + cost;
                parent[v] = u;
                pq.push({dist[v][p], {v, p}});
            }
        }
    }

    int v = n - 1;
    while (v != 0) {
        int u = parent[v];
        for (Edge& e : graph[u]) {
            if (e.to == v) {
                roads.push_back({u, v});
                break;
            }
        }
        v = u;
    }

    cout << roads.size() << endl;
    for (int i = 0; i < roads.size(); i++) {
        int x = roads[i].first + 1;
        int y = roads[i].second + 1;
        int z = 1;
        for (Edge& e : graph[roads[i].first]) {
            if (e.to == roads[i].second && e.cost == 0) {
                z = 0;
                break;
            }
        }
        cout << x << " " << y << " " << z << endl;
    }

    return 0;
}