#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> caves(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        caves[u].push_back(v);
        caves[v].push_back(u);
    }

    vector<int> dist(n + 1, -1);
    vector<int> parent(n + 1, 0);
    queue<int> q;
    q.push(1);
    dist[1] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int next : caves[curr]) {
            if (dist[next] == -1) {
                dist[next] = dist[curr] + 1;
                parent[next] = curr;
                q.push(next);
            }
        }
    }

    if (dist[n] == -1) {
        cout << -1 << endl;
    } else {
        cout << dist[n] << endl;
        vector<int> path;
        for (int i = n; i != 0; i = parent[i]) {
            path.push_back(i);
        }
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i] << " ";
        }
        cout << endl;
    }

    return 0;
}