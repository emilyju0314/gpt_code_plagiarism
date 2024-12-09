#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

const int INF = INT_MAX;

int main() {
    int n, m, k, s;
    cin >> n >> m >> k >> s;

    vector<int> goods(n);
    for (int i = 0; i < n; i++) {
        cin >> goods[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> dist(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
        vector<int> d(n, INF);
        d[i] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, i});
        while (!pq.empty()) {
            int u = pq.top().second;
            int dist_u = pq.top().first;
            pq.pop();
            if (dist[i][u] < dist_u) continue;
            for (int v : adj[u]) {
                int w = (goods[i] == goods[v]) ? 0 : 1;
                if (d[v] > d[u] + w) {
                    d[v] = d[u] + w;
                    dist[i][v] = d[v];
                    pq.push({d[v], v});
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        vector<int> sorted_dist;
        for (int j = 0; j < n; j++) {
            if (dist[i][j] != INF) {
                sorted_dist.push_back(dist[i][j]);
            }
        }
        sort(sorted_dist.begin(), sorted_dist.end());
        int total_expenses = 0;
        for (int j = 0; j < s; j++) {
            total_expenses += sorted_dist[j];
        }
        cout << total_expenses << " ";
    }
    cout << endl;

    return 0;
}