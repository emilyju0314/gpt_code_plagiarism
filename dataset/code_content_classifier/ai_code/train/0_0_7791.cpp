#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    vector<bool> visited(N + 1, false);
    visited[1] = true;

    int iterations = 0;
    bool stop = false;
    while (!q.empty()) {
        int size = q.size();
        iterations++;
        for (int i = 0; i < size; i++) {
            int curr = q.front();
            q.pop();
            for (int neighbor : adj[curr]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                    if (visited == true) {
                        stop = true;
                        break;
                    }
                }
            }
            if (stop) break;
        }
        if (stop) break;
    }

    if (stop) {
        cout << iterations << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}