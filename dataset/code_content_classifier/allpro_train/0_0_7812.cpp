#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    vector<int> dist(n + 1, 0);
    vector<bool> visited(n + 1, false);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                dist[neighbor] = dist[curr] + 1;
                q.push(neighbor);
            }
        }
    }

    int maxDist = 0, index = 1;
    for (int i = 1; i <= n; i++) {
        if (dist[i] > maxDist) {
            maxDist = dist[i];
            index = i;
        }
    }

    cout << 2 * (n - 1) - maxDist << endl;

    for (int i = 1; i <= n; i++) {
        if (i != index) {
            cout << i << " ";
        }
    }
    cout << index << endl;

    return 0;
}