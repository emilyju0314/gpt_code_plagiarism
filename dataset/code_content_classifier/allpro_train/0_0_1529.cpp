#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

struct Edge {
    int to, weight;
};

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<Edge>> graph(n);
    vector<int> dist(n, INF);
    dist[0] = 0;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        graph[a].push_back({b, c});
    }

    while (q--) {
        int query_type;
        cin >> query_type;

        if (query_type == 1) {
            int v;
            cin >> v;
            v--;

            if (dist[v] == INF) {
                cout << -1 << endl;
            } else {
                cout << dist[v] << endl;
            }
        } else {
            int c;
            cin >> c;

            for (int i = 0; i < c; i++) {
                int idx;
                cin >> idx;
                idx--;

                for (int j = 0; j < n; j++) {
                    for (Edge& e : graph[j]) {
                        if (e.to == idx) {
                            dist[e.to] = min(dist[e.to], dist[j] + 1);
                        }
                    }
                }
            }
        }
    }

    return 0;
}