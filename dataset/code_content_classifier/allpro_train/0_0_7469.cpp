#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

const int INF = 1e9;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        unordered_map<int, vector<int>> adj;
        vector<int> in_degree(n + 1, 0);
        vector<int> num_paths(n + 1, 0);
        vector<int> visited(n + 1, 0);
        vector<int> result(n + 1, 0);

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            in_degree[b]++;
        }

        queue<int> q;
        q.push(1);
        visited[1] = 1;
        num_paths[1] = 1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (visited[v] == 0) {
                    visited[v] = 1;
                }
                in_degree[v]--;

                if (in_degree[v] == 0) {
                    q.push(v);
                }

                if (num_paths[v] == 0) {
                    num_paths[v] = num_paths[u];
                } else if (num_paths[v] == 1) {
                    num_paths[v] = 2;
                }
            }
        }

        for (int v = 1; v <= n; v++) {
            if (visited[v] == 0) {
                result[v] = 0;
            } else if (num_paths[v] == 0) {
                result[v] = 1;
            } else if (visited[v] == 1) {
                result[v] = (in_degree[v] > 0 ? -1 : num_paths[v]);
            }
        }

        for (int v = 1; v <= n; v++) {
            cout << result[v] << " ";
        }
        cout << "\n";
    }

    return 0;
}