#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 2e5 + 5;

vector<pair<int, int>> adj[MAXN];
int dist[MAXN];

void dijkstra(int start, int n) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill(dist, dist + n + 1, INT_MAX);
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int curr_dist = pq.top().first;
        pq.pop();

        if (curr_dist > dist[u]) continue;

        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, a, b, c;
        cin >> n >> m >> a >> b >> c;

        vector<int> prices(m);
        for (int i = 0; i < m; i++) {
            cin >> prices[i];
        }

        sort(prices.begin(), prices.end());

        for (int i = 0; i < MAXN; i++) {
            adj[i].clear();
        }

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back({v, prices[i]});
            adj[v].push_back({u, prices[i]});
        }

        dijkstra(a, n);
        long long ab = dist[b];

        dijkstra(b, n);
        long long bc = dist[c];

        dijkstra(c, n);
        long long ac = dist[a];

        long long ans = LLONG_MAX;

        for (int i = 1; i <= n; i++) {
            ans = min(ans, ab + bc + ac + dist[i]);
        }

        cout << ans << endl;
    }

    return 0;
}