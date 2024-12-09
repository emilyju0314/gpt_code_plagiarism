#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<pair<int, int>>> adj(N+1);
    vector<int> color(N+1, -1); // -1 represents uncolored
    vector<int> dist(N+1, -1);

    for (int i = 0; i < N-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    queue<int> q;
    q.push(1);
    dist[1] = 0;
    color[1] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto p : adj[u]) {
            int v = p.first;
            int w = p.second;
            if (dist[v] == -1) {
                dist[v] = dist[u] + w;
                color[v] = color[u] ^ 1;
                q.push(v);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << color[i] << endl;
    }

    return 0;
}