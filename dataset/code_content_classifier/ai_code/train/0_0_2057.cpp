#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> A(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    // Initialize the distance matrix with the initial graph
    vector<vector<int>> dist(N, vector<int>(N, INF));
    for (int i = 0; i < N; i++) {
        dist[i][i] = 0;
        if (i < N - 1) {
            dist[i][i + 1] = 0;
            dist[i + 1][i] = -1;
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int min_cost = INF;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j) {
                min_cost = min(min_cost, dist[i][j] + A[i][j]);
            }
        }
    }

    cout << min_cost << endl;

    return 0;
}