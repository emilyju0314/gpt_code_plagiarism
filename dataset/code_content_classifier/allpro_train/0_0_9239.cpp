#include <iostream>
#include <vector>

using namespace std;

bool isLeaderPair(int u, int v, vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    vector<int> dist(adj.size(), -1);

    visited[u] = true;
    dist[u] = 0;

    vector<int> queue;
    queue.push_back(u);

    while (!queue.empty()) {
        int curr = queue.front();
        queue.erase(queue.begin());

        for (int i = 0; i < adj[curr].size(); i++) {
            int next = adj[curr][i];
            if (!visited[next]) {
                visited[next] = true;
                dist[next] = dist[curr] + 1;
                queue.push_back(next);
            }
        }
    }

    if (dist[v] % 2 == 1) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        if (isLeaderPair(u, v, adj)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}