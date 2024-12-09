#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

#define INF INT_MAX

struct City {
    int id, value, distance;
};

struct Edge {
    int to, weight;
};

void dijkstra(int start, vector<vector<Edge>>& graph, vector<int>& distances) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    distances[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        for (const Edge& e : graph[u]) {
            int v = e.to;
            int weight = e.weight;

            if (dist + weight < distances[v]) {
                distances[v] = dist + weight;
                pq.push({distances[v], v});
            }
        }
    }
}

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<int> cities(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> cities[i];
    }

    vector<vector<Edge>> graph(n+1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<int> dist_s(n+1, INF);
    vector<int> dist_t(n+1, INF);
    dijkstra(s, graph, dist_s);
    dijkstra(t, graph, dist_t);

    int tavas_score = 0, nafas_score = 0;
    for (int i = 1; i <= n; i++) {
        if (dist_s[i] < dist_t[i]) {
            tavas_score += cities[i];
        } else if (dist_s[i] > dist_t[i]) {
            nafas_score += cities[i];
        }
    }

    if (tavas_score > nafas_score) {
        cout << "Break a heart" << endl;
    } else if (tavas_score < nafas_score) {
        cout << "Cry" << endl;
    } else {
        cout << "Flowers" << endl;
    }

    return 0;
}