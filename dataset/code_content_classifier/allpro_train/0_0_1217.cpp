#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int main() {
    int K, N, M;
    cin >> K >> N >> M;

    // Initialize the piping network
    vector<vector<int>> graph(K + N + 1, vector<int>(K + N + 1, 0));

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
        graph[b][a] = c;
    }

    int max_hot_water = 0;

    // Loop over all pipes
    for (int i = 1; i <= K + N; i++) {
        for (int j = i + 1; j <= K + N; j++) {
            if (graph[i][j]) {
                int total = 0;

                // Remove the limit of current pipe (overflow)
                graph[i][j] = 0;
                graph[j][i] = 0;

                // Calculate the maximum hot water supply
                vector<int> dist(K + N + 1, 0);
                vector<bool> visited(K + N + 1, false);
                dist[0] = INT_MAX;

                for (int k = 0; k < K + N; k++) {
                    int max_dist = 0, u = -1;
                    for (int l = 0; l <= K + N; l++) {
                        if (!visited[l] && dist[l] > max_dist) {
                            max_dist = dist[l];
                            u = l;
                        }
                    }

                    if (u == -1) break;

                    visited[u] = true;

                    for (int v = 0; v <= K + N; v++) {
                        if (!visited[v] && graph[u][v] > 0) {
                            dist[v] = max(dist[v], min(dist[u], graph[u][v]));
                        }
                    }
                }

                if (dist[K] > max_hot_water) {
                    max_hot_water = dist[K];
                }

                if (dist[K] == INT_MAX) {
                    cout << "overfuro" << endl;
                    return 0;
                }

                // Restore the limit of current pipe
                graph[i][j] = dist[i];
                graph[j][i] = dist[j];
            }
        }
    }

    cout << max_hot_water << endl;

    return 0;
}