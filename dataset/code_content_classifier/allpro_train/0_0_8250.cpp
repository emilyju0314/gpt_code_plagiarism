#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>>& graph, vector<int>& dist, int start) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int neighbor : graph[curr]) {
            if (dist[neighbor] > dist[curr] + 1) {
                dist[neighbor] = dist[curr] + 1;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> graph(n + 1);
        vector<int> dist(n + 1, INT_MAX);
        
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
        }

        bfs(graph, dist, 1);

        for (int i = 1; i <= n; i++) {
            cout << dist[i] << " ";
        }
        cout << endl;
    }

    return 0;
}