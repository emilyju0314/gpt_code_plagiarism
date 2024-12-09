#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 1000000000

int main() {
    int N, M, P;
    cin >> N >> M >> P;

    vector<vector<pair<int, int>>> edges(N+1); // Adjacency list to store edges
    vector<int> dist(N+1, INF); // Distance array to store maximum coins at each vertex

    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        edges[A].push_back({B, C});
    }

    dist[1] = 0;

    for (int k = 0; k < N; k++) {
        for (int i = 1; i <= N; i++) {
            for (auto option : edges[i]) {
                int next = option.first;
                int coins = option.second;
                if (dist[i] != INF && dist[i] + coins - P < dist[next]) {
                    dist[next] = max(0, dist[i] + coins - P);
                }
            }
        }
    }

    if (dist[N] < 0) {
        cout << "-1" << endl; // It's not possible to achieve a positive score
    } else {
        cout << dist[N] << endl; // Maximum positive score achieved
    }

    return 0;
}