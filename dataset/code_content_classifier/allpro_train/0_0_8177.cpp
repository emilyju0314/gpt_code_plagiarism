#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

struct Edge {
    int u, v, w;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    int q;
    cin >> q;

    while (q--) {
        int ai, bi;
        cin >> ai >> bi;

        int ans = INF;

        for (int i = 0; i < m; i++) {
            vector<int> dist(n + 1, INF);
            dist[ai] = 0;

            for (int j = 0; j < n - 1; j++) {
                for (const auto& edge : edges) {
                    if (dist[edge.u] < INF) {
                        dist[edge.v] = min(dist[edge.v], dist[edge.u] + edge.w);
                    }
                    if (dist[edge.v] < INF) {
                        dist[edge.u] = min(dist[edge.u], dist[edge.v] + edge.w);
                    }
                }
            }

            ans = min(ans, dist[bi]);
        }

        if (ans == INF) {
            cout << "-1" << endl;
        } else {
            cout << ans << endl;
        }
    }

    return 0;
}