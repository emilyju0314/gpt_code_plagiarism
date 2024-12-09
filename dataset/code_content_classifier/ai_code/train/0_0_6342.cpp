#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> actions;
vector<int> mode_shifted;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            mode_shifted[u] = mode_shifted[v] ^ 1;
            actions.push_back(u + 1);
            actions.push_back(-1);
            dfs(u);
        }
    }
}

bool can_destroy_edges(int n, int m) {
    visited.assign(n, false);
    mode_shifted.assign(n, 0);
    actions.clear();

    dfs(0);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    if (can_destroy_edges(n, m)) {
        cout << actions.size() + 1 << endl;
        cout << "1 ";
        for (int a : actions) {
            cout << a << " ";
        }
        cout << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}