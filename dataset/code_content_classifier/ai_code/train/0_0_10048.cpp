#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<pair<int, int>>> adj(n);
    vector<int> heights(n, 0);

    for (int i = 0; i < n-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for (int i = 0; i < n; i++) {
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(i);
        visited[i] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (auto& neighbor : adj[curr]) {
                int next = neighbor.first;
                int weight = neighbor.second;
                if (!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                    heights[i] = max(heights[i], heights[curr] + weight);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << heights[i] << endl;
    }

    return 0;
}