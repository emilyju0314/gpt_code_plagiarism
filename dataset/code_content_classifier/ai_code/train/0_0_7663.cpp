#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];

bool visited[MAXN];
int direction[MAXN]; // 0: no direction, 1: forward, 2: backward

bool dfs(int node, int dir) {
    visited[node] = true;
    direction[node] = dir;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (!dfs(neighbor, (dir == 1 ? 2 : 1))) {
                return false;
            }
        } else {
            if (direction[neighbor] == dir) {
                return false;
            }
        }
    }
    
    return true;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    fill(visited, visited + n + 1, false);
    fill(direction, direction + n + 1, 0);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (!dfs(i, 1)) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;

    return 0;
}