#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(n, vector<int>(n, INF));

    for (int i = 0; i < m; ++i) {
        int a, b, c1, c2;
        cin >> a >> b >> c1 >> c2;
        --a; --b;
        edges[a][b] = c1;
        edges[b][a] = c2;
    }

    int ans = INF;
    for (int k = 0; k < n; ++k) {
        vector<vector<int>> dist(n, vector<int>(n, INF));
        for (int i = 0; i < n; ++i) dist[i][i] = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (edges[i][j] != INF) {
                    dist[i][j] = edges[i][j];
                }
            }
        }

        for (int t = 0; t < n; ++t) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][t] < INF && dist[t][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][t] + dist[t][j]);
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (dist[i][i] < 0) {
                ans = min(ans, dist[i][i]);
            }
        }
    }

    if(ans == INF) {
        cout << "0" << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}