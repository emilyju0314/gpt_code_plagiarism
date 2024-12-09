#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = INT_MAX;

void dijkstra(int start, int n, vector<vector<pair<int, int>>>& adj, vector<int>& dist) {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, 1});
        adj[v].push_back({u, 1});
    }

    int w;
    cin >> w;

    vector<pair<int, int>> stores(w);
    for (int i = 0; i < w; i++) {
        int city, numShovels, price;
        cin >> city >> numShovels >> price;
        stores[i] = {city, numShovels * price};
    }

    sort(stores.begin(), stores.end());

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int targetCity, numShovels, budget;
        cin >> targetCity >> numShovels >> budget;

        vector<int> dist(n + 1, INF);
        dijkstra(targetCity, n, adj, dist);

        int minTime = -1;
        for (auto& store : stores) {
            int city = store.first;
            int totalPrice = store.second;
            int time = dist[city];
            int maxShovels = min(numShovels, budget / totalPrice);

            if (maxShovels > 0 && (minTime == -1 || time < minTime)) {
                minTime = time;
            }
        }

        cout << minTime << endl;
    }

    return 0;
}