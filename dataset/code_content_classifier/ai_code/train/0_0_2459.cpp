#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Edge {
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(Edge(b, c));
        adj[b].push_back(Edge(a, c));
    }

    vector<vector<int>> arrivalTimes(n+1);
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        int arrivalTime;
        for (int j = 0; j < k; j++) {
            cin >> arrivalTime;
            arrivalTimes[i].push_back(arrivalTime);
        }
    }

    vector<int> dist(n+1, numeric_limits<int>::max());
    dist[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (Edge& e : adj[u]) {
            int v = e.to;
            int w = e.weight;
            int transferTime = dist[u] + w;
            for (int arrivalTime : arrivalTimes[v]) {
                if (transferTime == arrivalTime) transferTime++;
                if (transferTime < arrivalTime) transferTime = arrivalTime + 1;
            }
            if (transferTime < dist[v]) {
                dist[v] = transferTime;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[n] == numeric_limits<int>::max()) {
        cout << -1 << endl;
    } else {
        cout << dist[n] << endl;
    }

    return 0;
}