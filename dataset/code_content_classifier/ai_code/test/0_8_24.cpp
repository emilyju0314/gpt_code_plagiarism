#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const long long INF = 1e18;

struct Edge {
    int to;
    long long weight;
};

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<long long> w(n);
    for(int i = 0; i < n; i++) {
        cin >> w[i];
    }

    vector<vector<Edge>> graph(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        long long d;
        cin >> u >> v >> d;
        u--; v--;
        graph[u].push_back({v, d});
        graph[v].push_back({u, d});
    }

    vector<long long> dist(n, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[0] = 0;
    pq.push({0, 0});

    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if(d > dist[u]) continue;
        for(Edge& e : graph[u]) {
            int v = e.to;
            long long w_uv = e.weight;
            if(dist[u] + w_uv < dist[v]) {
                dist[v] = dist[u] + w_uv;
                pq.push({dist[v], v});
            }
        }
    }

    long long initial_cost = 0;
    for(int i = 1; i < n; i++) {
        initial_cost += dist[i] * 2;
    }

    cout << initial_cost << endl;

    while(q--) {
        int k;
        long long x;
        cin >> k >> x;
        k--;
        w[k] += x;

        long long updated_cost = 0;
        for(int i = 1; i < n; i++) {
            if(dist[i] + w[i] < dist[0] + w[0] + w[i]) { // Compare two shortest paths from station 1 to station i
                updated_cost += (dist[i] + w[i]) * 2;
            } else {
                updated_cost += (dist[0] + w[0] + w[i]);
            }
        }

        cout << updated_cost << endl;
    }

    return 0;
}