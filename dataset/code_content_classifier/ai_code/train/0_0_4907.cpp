#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void dijkstra(int start, vector<vector<pair<int, int>>>& graph, vector<int>& distances) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    distances[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        if (dist > distances[u]) {
            continue;
        }

        for (auto edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist + weight < distances[v]) {
                distances[v] = dist + weight;
                pq.push({distances[v], v});
            }
        }
    }
}

int main() {
    int n, m, k, s;
    cin >> n >> m >> k >> s;

    vector<int> goods(n);
    for (int i = 0; i < n; i++) {
        cin >> goods[i];
    }

    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back({v, 1});
        graph[v].push_back({u, 1});
    }

    vector<vector<int>> goodsPerType(k+1);
    for (int i = 0; i < n; i++) {
        goodsPerType[goods[i]].push_back(i);
    }

    for (int i = 1; i <= k; i++) {
        vector<int> distances(n, INT_MAX);
        for (int town : goodsPerType[i]) {
            dijkstra(town, graph, distances);
        }

        for (int j = 0; j < n; j++) {
            cout << distances[j] << " ";
        }
        cout << endl;
    }

    return 0;
}