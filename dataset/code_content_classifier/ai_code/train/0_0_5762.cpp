#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

bool bfs(int s, int t, vector<vector<int>>& adjList, vector<bool>& visited, vector<int>& parent) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adjList[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    return visited[t];
}

void solve() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<vector<int>> adjList(n+1);
    vector<pair<int, int>> roads;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        roads.push_back({u, v});
    }

    vector<bool> visited(n+1, false);
    vector<int> parent(n+1, -1);
    if (!bfs(s, t, adjList, visited, parent)) {
        cout << "No" << endl;
        return;
    }

    cout << "Yes" << endl;
    for (auto road : roads) {
        if (parent[road.second] == road.first) {
            cout << road.first << " " << road.second << endl;
        } else {
            cout << road.second << " " << road.first << endl;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}