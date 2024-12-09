#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        dist[u-1][v-1] = 1; // all roads have the same length
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    int maxDist = 0;
    vector<int> cities;

    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
            for (int c = 0; c < n; c++) {
                for (int d = 0; d < n; d++) {
                    if (a != b && a != c && a != d && b != c && b != d && c != d) {
                        int totalDist = dist[a][b] + dist[b][c] + dist[c][d];
                        if (totalDist > maxDist) {
                            maxDist = totalDist;
                            cities = {a+1, b+1, c+1, d+1};
                        }
                    }
                }
            }
        }
    }

    for (int city : cities) {
        cout << city << " ";
    }

    return 0;
}