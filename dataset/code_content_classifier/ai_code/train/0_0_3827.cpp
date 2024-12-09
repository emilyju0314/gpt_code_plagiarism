#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
    }

    vector<vector<long long>> dist(n, vector<long long>(n, INF));
    for (int i = 0; i < n; i++) {
        set<pair<long long, int>> s;
        dist[i][i] = 0;
        s.insert({0, i});
        while (!s.empty()) {
            int v = s.begin()->second;
            s.erase(s.begin());
            for (auto edge : adj[v]) {
                int to = edge.first, len = edge.second;
                if (dist[i][v] + len < dist[i][to]) {
                    s.erase({dist[i][to], to});
                    dist[i][to] = dist[i][v] + len;
                    s.insert({dist[i][to], to});
                }
            }
        }
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        double ans = dist[0][n-1] + min(x, (int)sqrt(x));
        cout << fixed << setprecision(10) << ans << endl;
    }

    return 0;
}