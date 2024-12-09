#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    int N, R;
    cin >> N >> R;

    vector<vector<int>> dist(N, vector<int>(N, INF));

    for (int i = 0; i < N; i++) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < R; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        dist[s-1][t-1] = dist[t-1][s-1] = d;
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    vector<int> candidateTowns;

    for (int i = 0; i < N; i++) {
        int maxDist = 0;
        for (int j = 0; j < N; j++) {
            if (dist[i][j] != INF) {
                maxDist = max(maxDist, dist[i][j]);
            }
        }

        bool isMaxDist = true;
        for (int j = 0; j < N; j++) {
            if (dist[i][j] != INF && dist[i][j] == maxDist) {
                isMaxDist = false;
                break;
            }
        }

        if (isMaxDist) {
            candidateTowns.push_back(i+1);
        }
    }

    cout << candidateTowns.size() << endl;
    for (int town : candidateTowns) {
        cout << town << endl;
    }

    return 0;
}