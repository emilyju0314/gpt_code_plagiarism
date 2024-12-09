#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n+1);
    vector<int> parent(n+1, -1);

    for (int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    queue<int> q;
    q.push(1);
    parent[1] = 0;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (parent[v] == -1) {
                parent[v] = u;
                q.push(v);
            }
        }
    }

    auto query = [&](int u, int v) {
        cout << "? " << u << " " << v << endl;
        cout.flush();
        int w;
        cin >> w;
        return w;
    };

    auto findLCA = [&](int u, int v) {
        vector<int> path;
        while (u != 0) {
            path.push_back(u);
            u = parent[u];
        }

        while (v != 0) {
            if (find(path.begin(), path.end(), v) != path.end()) {
                return v;
            }
            v = parent[v];
        }

        return -1; // should not happen
    };

    for (int i = 0; i < n/2; i++) {
        int u, v;
        u = i + 1;
        v = n - i;
        int w = query(u, v);
        if (w == u || w == v) {
            cout << "! " << w << endl;
            cout.flush();
            return 0;
        }
        int lca = findLCA(u, v);
        if (lca != -1) {
            cout << "! " << lca << endl;
            cout.flush();
            return 0;
        }
    }

    cout << -1 << endl;
    cout.flush();

    return 0;
}