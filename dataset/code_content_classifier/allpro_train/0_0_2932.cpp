#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 105;

int adj[MAXN][MAXN];
bool vis[MAXN];
vector<int> path;

void dfs(int u) {
    vis[u] = true;
    path.push_back(u);
    for (int v = 1; v < MAXN; v++) {
        if (adj[u][v] && !vis[v]) {
            dfs(v);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    memset(adj, 0, sizeof(adj));

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = adj[b][a] = 1;
    }

    // Check if there is an Eulerian tour
    bool eulerian = true;
    for (int i = 1; i <= n; i++) {
        int degree = 0;
        for (int j = 1; j <= n; j++) {
            degree += adj[i][j];
        }
        if (degree % 2) {
            eulerian = false;
            break;
        }
    }

    if (!eulerian) {
        cout << -1 << endl;
    } else {
        // Find a Eulerian tour
        memset(vis, 0, sizeof(vis));
        dfs(1);

        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                cout << n - path.size() << endl;
                for (int j = 1; j < path.size(); j++) {
                    cout << path[j-1] << " " << path[j] << endl;
                }
                break;
            }
        }
    }

    return 0;
}