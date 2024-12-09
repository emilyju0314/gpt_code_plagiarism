#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Road {
    int u, v, d, c;
};

int main() {
    int N, M;
    while (cin >> N >> M && N != 0 && M != 0) {
        vector<Road> roads(M);
        for (int i = 0; i < M; i++) {
            cin >> roads[i].u >> roads[i].v >> roads[i].d >> roads[i].c;
        }

        vector<vector<int>> dist(N + 1, vector<int>(N + 1, INT_MAX));
        for (int i = 1; i <= N; i++) {
            dist[i][i] = 0;
        }

        for (int i = 0; i < M; i++) {
            dist[roads[i].u][roads[i].v] = dist[roads[i].v][roads[i].u] = roads[i].d;
        }

        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int min_cost = 0;
        for (int i = 2; i <= N; i++) {
            min_cost += dist[1][i];
        }
        
        cout << min_cost << endl;
    }

    return 0;
}