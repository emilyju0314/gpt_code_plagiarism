#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<pair<int, int>> undirectedEdges;
    for (int i = 0; i < m; i++) {
        int type, u, v;
        cin >> type >> u >> v;
        if (type == 1) {
            adj[u].push_back({1, v});
        } else {
            adj[u].push_back({2, v});
            adj[v].push_back({2, u});
            undirectedEdges.push_back({u, v});
        }
    }

    vector<bool> vis(n + 1);
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto edge : adj[u]) {
            int type = edge.first;
            int v = edge.second;
            if (!vis[v] && type != 1) {
                q.push(v);
                vis[v] = true;
            }
        }
    }

    cout << count(vis.begin(), vis.end(), true) << endl;
    for (auto edge : undirectedEdges) {
        if (vis[edge.first] && vis[edge.second]) {
            cout << '+';
        } else {
            cout << '-';
        }
    }
    cout << endl;

    fill(vis.begin(), vis.end(), false);
    q.push(s);
    vis[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto edge : adj[u]) {
            int type = edge.first;
            int v = edge.second;
            if (!vis[v] && type != 1) {
                q.push(v);
                vis[v] = true;
            }
        }
    }

    cout << count(vis.begin(), vis.end(), true) << endl;
    for (auto edge : undirectedEdges) {
        if (!vis[edge.first] && !vis[edge.second]) {
            cout << '+';
        } else {
            cout << '-';
        }
    }
    cout << endl;

    return 0;
}