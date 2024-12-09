#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int INF = 1e9;

int main() {
    int n, s, t;

    while (cin >> n >> s >> t && n != 0) {
        vector<vector<int>> graph(n, vector<int>(n)), sign(n);
        vector<double> dist(n, INF);
        vector<double> prob(n, 0.0);
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> sign[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> graph[i][j];
            }
        }

        dist[s-1] = 0.0;
        prob[s-1] = 1.0;

        for (int i = 0; i < n-1; i++) {
            int u = -1;
            for (int j = 0; j < n; j++) {
                if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                    u = j;
                }
            }

            visited[u] = true;

            for (int v = 0; v < n; v++) {
                if (graph[u][v] != 0) {
                    if (dist[v] > dist[u] + graph[u][v]) {
                        dist[v] = dist[u] + graph[u][v];
                        prob[v] = prob[u] * (1.0 / (sign[u][v] + 1.0));
                    } else if (dist[v] == dist[u] + graph[u][v]) {
                        prob[v] += prob[u] * (1.0 / (sign[u][v] + 1.0));
                    }
                }
            }
        }

        if (dist[t-1] == INF) {
            cout << "impossible" << endl;
        } else {
            cout << fixed << setprecision(9) << dist[t-1] << endl;
        }
    }

    return 0;
}