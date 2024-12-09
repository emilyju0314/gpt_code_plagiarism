#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> color, parent;
int n, m, cycle_start, cycle_end;

bool dfs(int v, int p) {
    color[v] = 1;
    for (int u : adj[v]) {
        if (u == p) continue;
        if (color[u] == 0) {
            parent[u] = v;
            if (dfs(u, v)) return true;
        } else if (color[u] == 1) {
            cycle_start = u;
            cycle_end = v;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

int main() {
    cin >> n >> m;

    adj.resize(n + 1);
    color.resize(n + 1, 0);
    parent.resize(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (color[i] == 0 && dfs(i, -1)) break;
    }

    if (cycle_start == 0) {
        cout << 0 << endl;
    } else {
        cout << m << endl;
        for (int i = 1; i <= n; i++) {
            for (int j : adj[i]) {
                if ((i == cycle_start && j == cycle_end) || (i == cycle_end && j == cycle_start)) {
                    cout << i << " " << j << endl;
                } else {
                    cout << j << " " << i << endl;
                }
            }
        }
    }

    return 0;
}