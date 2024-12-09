#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 2e5 + 5;

vector<int> adj[MAXN];
int color[MAXN];

bool dfs(int u, int c) {
    color[u] = c;
    for (int v : adj[u]) {
        if (color[v] == -1) {
            if (!dfs(v, c ^ 1)) {
                return false;
            }
        } else if (color[v] == c) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        // Clear previous data
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }

        // Read comments and build graph
        for (int i = 0; i < m; i++) {
            int u, v;
            string c;
            cin >> u >> v >> c;
            if (c == "imposter") {
                adj[u].push_back(v);
            } else {
                adj[v].push_back(u);
            }
        }

        // Initialize color array
        memset(color, -1, sizeof(color));

        int imposters = 0;
        bool contradiction = false;

        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                if (!dfs(i, 0)) {
                    contradiction = true;
                    break;
                }
            }
            if (color[i] == 1) {
                imposters++;
            }
        }

        if (contradiction) {
            cout << -1 << endl;
        } else {
            cout << imposters << endl;
        }
    }

    return 0;
}