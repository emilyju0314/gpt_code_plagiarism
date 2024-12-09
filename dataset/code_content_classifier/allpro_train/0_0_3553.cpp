#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isCthulhu(int n, vector<vector<int>>& adj) {
    if (adj.size() != n) {
        return false;
    }

    vector<int> visited(n, 0);

    queue<int> q;
    q.push(0);
    visited[0] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (visited[v] == 0) {
                q.push(v);
                visited[v] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            return false;
        }
    }

    if (adj.size() == n && adj.size() == adj[0].size()) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }

    if (isCthulhu(n, adj)) {
        cout << "FHTAGN!" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}