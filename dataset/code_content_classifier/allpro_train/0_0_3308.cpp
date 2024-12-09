#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n + 1);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> distances(n + 1, 0);
    vector<int> parent(n + 1, 0);
    vector<bool> visited(n + 1, false);

    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
                distances[neighbor] = distances[node] + 1;
                parent[neighbor] = node;
            }
        }
    }

    // Output the smallest total length of the shortest paths
    cout << 2 * (n - 1) << endl;

    // Output example assignment of new houses
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            cout << distances[i] + 1 << " ";
        } else {
            int curr = i;
            while (distances[curr] > distances[parent[curr]]) {
                curr = parent[curr];
            }
            cout << curr << " ";
        }
    }

    return 0;
}