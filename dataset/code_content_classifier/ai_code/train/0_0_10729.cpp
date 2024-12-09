#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
using namespace std;

const int inf = numeric_limits<int>::max();

struct Edge {
    int to, cost;
    Edge(int _to, int _cost) : to(_to), cost(_cost) {}
};

void dijkstra(int start, int n, vector<vector<Edge>>& graph, vector<int>& dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto edge : graph[u]) {
            int v = edge.to;
            int cost = edge.cost;

            if (dist[u] + cost < dist[v]) {
                dist[v] = dist[u] + cost;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n+1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(Edge(b, c));
    }

    vector<int> original_dist(n+1, inf);
    dijkstra(1, n, graph, original_dist);

    vector<int> new_dist(n+1, inf);
    vector<int> reversed_dist(n+1, inf);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        for (int j = 1; j <= n; j++) {
            new_dist[j] = original_dist[j];
            reversed_dist[j] = original_dist[j];
        }

        // Change the direction of the street section
        for (auto& edge : graph[a]) {
            if (edge.to == b) {
                edge.to = a;
                break;
            }
        }

        dijkstra(1, n, graph, reversed_dist);

        for (int j = 1; j <= n; j++) {
            if (reversed_dist[j] < new_dist[j]) {
                cout << "HAPPY" << endl;
            } else if (reversed_dist[j] == new_dist[j]) {
                cout << "SOSO" << endl;
            } else {
                cout << "SAD" << endl;
            }
        }

        // Revert the direction of the street section
        for (auto& edge : graph[a]) {
            if (edge.to == a) {
                edge.to = b;
                break;
            }
        }
    }

    return 0;
}