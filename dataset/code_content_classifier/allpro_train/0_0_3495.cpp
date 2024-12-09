#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> leaves_order, visited;
vector<bool> is_leaf;

void dfs(int u, int p) {
    bool has_non_leaf_child = false;
    for (int v : adj[u]) {
        if (v != p) {
            has_non_leaf_child = true;
            dfs(v, u);
        }
    }
    if (!has_non_leaf_child) {
        is_leaf[u] = true;
    }
}

bool check_order(int n) {
    int pos = 0;
    for (int i = 0; i < n; i++) {
        if (!is_leaf[leaves_order[i]]) {
            pos = i;
            break;
        }
    }
    while (pos < n) {
        if (!is_leaf[leaves_order[pos]]) {
            return false;
        }
        pos++;
    }
    return true;
}

void bfs(int root) {
    queue<int> q;
    q.push(root);
    visited[root] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (visited[v] == 0) {
                visited[v] = 1;
                cout << u << " ";
                cout << v << " ";
                q.push(v);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n+1);
    is_leaf.resize(n+1, false);
    visited.resize(n+1, 0);

    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    int k;
    cin >> k;
    leaves_order.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> leaves_order[i];
    }

    if (!check_order(k)) {
        cout << -1 << endl;
    } else {
        bfs(1);
    }

    return 0;
}