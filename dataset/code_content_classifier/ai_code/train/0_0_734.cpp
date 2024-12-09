#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> railways(n + 1, vector<int>(n + 1, 0));
    vector<bool> visited(n + 1, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        railways[u][v] = railways[v][u] = 1;
    }

    // Perform a BFS with the train
    queue<int> q;
    q.push(1);
    vector<int> train_dist(n + 1, INF);
    train_dist[1] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (railways[curr][i] == 1 && train_dist[i] == INF) {
                train_dist[i] = train_dist[curr] + 1;
                q.push(i);
            }
        }
    }

    // Find the minimum distance for the bus
    for (int i = 2; i <= n; i++) {
        if (train_dist[i] == 1) {
            // Train reaches town i in 1 hour, so we cannot let the bus reach it at the same time
            cout << -1 << endl;
            return 0;
        }
    }

    int min_time = 0;
    for (int i = 2; i <= n; i++) {
        min_time = max(min_time, train_dist[i]);
    }

    cout << min_time << endl;
    return 0;
}