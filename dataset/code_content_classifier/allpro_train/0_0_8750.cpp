#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> adj(n + 1);
    vector<int> degree(n + 1, 0);
    
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
        degree[v]++;
        degree[u]++;
    }

    queue<int> path;
    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; i++) {
        if (degree[i] < 3) {
            for (int j : adj[i]) {
                if (degree[j] >= 3) {
                    path.push(i);
                    visited[i] = true;
                    break;
                }
            }
        }
    }

    if (path.size() == 0) {
        cout << -1 << endl;
        return 0;
    }

    cout << "PATH" << endl;
    cout << path.size() + 1 << endl;
    while(!path.empty()) {
        int v = path.front();
        path.pop();
        cout << v << ' ';
    }
    cout << path.front() << endl;

    if (k > 0) {
        cout << "CYCLES" << endl;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < 2; j++) {
                cout << "4" << endl;
                int v = path.front();
                cout << v << ' ';
                path.pop();
                for (int x : adj[v]) {
                    if (visited[x]) {
                        visited[x] = false;
                        cout << x << ' ';
                        break;
                    }
                }
                for (int x : adj[v]) {
                    if (visited[x]) {
                        visited[x] = false;
                        cout << x << ' ';
                        break;
                    }
                }
                cout << v << endl;
            }
        }
    }

    return 0;
}