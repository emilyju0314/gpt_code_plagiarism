#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    long long totalRisk = 0;
    for (int i = 0; i < n; i++) {
        vector<int> dist(n, INT_MAX);
        dist[i] = 0;
        vector<bool> visited(n, false);

        for (int j = 0; j < n - 1; j++) {
            int u = -1;
            for (int k = 0; k < n; k++) {
                if (!visited[k] && (u == -1 || dist[k] < dist[u])) {
                    u = k;
                }
            }

            visited[u] = true;
            for (auto neighbor : graph[u]) {
                int v = neighbor.first;
                int c = neighbor.second;
                dist[v] = min(dist[v], max(dist[u], c));
            }
        }

        for (int j = i + 1; j < n; j++) {
            totalRisk += dist[j];
        }
    }

    cout << totalRisk << endl;

    return 0;
}