#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> parent(n, -1);
    vector<int> depth(n);
    vector<int> subtreeValues(n);
    vector<int> ancestorValues(n);

    vector<int> dfsOrder;
    vector<int> firstOccurrence(n);
    vector<int> lastOccurrence(n);
    vector<bool> visited(n, false);

    function<void(int, int, int)> dfs = [&](int v, int p, int d) {
        parent[v] = p;
        depth[v] = d;
        
        visited[v] = true;
        dfsOrder.push_back(v);
        firstOccurrence[v] = dfsOrder.size() - 1;
        
        subtreeValues[v] = ancestorValues[v] = values[v];
        
        for (int u : adj[v]) {
            if (!visited[u]) {
                dfs(u, v, d + 1);
                subtreeValues[v] = gcd(subtreeValues[v], subtreeValues[u]);
            }
        }
        
        visited[v] = false;
        lastOccurrence[v] = dfsOrder.size() - 1;
    };

    dfs(0, -1, 0);

    while (q--) {
        int queryType;
        cin >> queryType;

        if (queryType == 1) {
            int v;
            cin >> v;
            v--;

            int maxstep = -1;
            int result = -1;
            for (int i = firstOccurrence[v] + 1; i <= lastOccurrence[v]; i++) {
                int u = dfsOrder[i];
                if (gcd(values[u], values[v]) > 1 && depth[u] > maxstep) {
                    maxstep = depth[u];
                    result = u + 1;
                }
            }
            cout << result << endl;
        } else {
            int v, w;
            cin >> v >> w;
            v--;
            values[v] = w;
            for (int u = v; u != -1; u = parent[u]) {
                subtreeValues[u] = values[u];
                for (int c : adj[u]) {
                    if (c != parent[u]) {
                        subtreeValues[u] = gcd(subtreeValues[u], subtreeValues[c]);
                    }
                }
            }
        }
    }

    return 0;
}