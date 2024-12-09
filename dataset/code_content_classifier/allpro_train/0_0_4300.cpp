#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    vector<vector<int>> adj(n);
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        
        u--;
        v--;
        
        adj[u].push_back(i);
        adj[v].push_back(i);
        
        edges[i] = {u, v};
    }

    vector<int> deg(n);
    for (int i = 0; i < n; i++) {
        deg[i] = adj[i].size();
    }

    int cnt = 0;
    vector<bool> used(m, false);
    for (int i = 0; i < n; i++) {
        if (d[i] == -1) {
            if (deg[i] % 2 == 1) {
                for (int e : adj[i]) {
                    if (!used[e]) {
                        used[e] = true;
                        cnt++;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (d[i] != -1) {
            if (deg[i] % 2 != d[i]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << cnt << endl;
    for (int i = 0; i < m; i++) {
        if (used[i]) {
            cout << i + 1 << endl;
        }
    }

    return 0;
}