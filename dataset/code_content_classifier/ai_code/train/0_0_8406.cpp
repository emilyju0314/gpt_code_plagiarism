#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;
vector<int> order;

void dfs(int v) {
    vis[v] = true;
    for (int u : adj[v]) {
        if (!vis[u]) {
            dfs(u);
        }
    }
    order.push_back(v);
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    vis.resize(n + 1, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }

    reverse(order.begin(), order.end());

    vector<vector<int>> rev_adj(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int u : adj[i]) {
            rev_adj[u].push_back(i);
        }
    }

    vis.assign(n + 1, false);
    dfs(order[0]);

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}