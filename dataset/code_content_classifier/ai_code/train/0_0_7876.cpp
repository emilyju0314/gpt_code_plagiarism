#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

struct Edge {
    int to, weight;
};

int main() {
    int n, m, k, p;
    cin >> n >> m >> k >> p;

    vector<vector<Edge>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x].push_back({y, w});
        graph[y].push_back({x, w});
    }

    vector<int> dropped_mails(k), delivery_destinations(k);
    for (int i = 0; i < k; i++) {
        cin >> dropped_mails[i] >> delivery_destinations[i];
    }

    vector<int> shortest_delivery_time(n + 1, INF);
    vector<int> visited(n + 1, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, p});
    shortest_delivery_time[p] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = 1;

        for (Edge& edge : graph[u]) {
            int v = edge.to, w = edge.weight;
            if (shortest_delivery_time[u] + w < shortest_delivery_time[v]) {
                shortest_delivery_time[v] = shortest_delivery_time[u] + w;
                pq.push({shortest_delivery_time[v], v});
            }
        }
    }

    int total_time = 0;
    for (int i = 0; i < k; i++) {
        total_time += shortest_delivery_time[delivery_destinations[i]];

        if (shortest_delivery_time[delivery_destinations[i]] == INF) {
            total_time = -1;
            break;
        }

        total_time += shortest_delivery_time[dropped_mails[i]];
    }

    if (total_time == -1) {
        cout << "Cannot deliver" << endl;
    } else {
        cout << total_time << endl;
    }

    return 0;
}