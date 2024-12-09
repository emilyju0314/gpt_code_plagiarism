#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 5;
vector<int> adj[MAXN];
vector<int> path;
bool visited[MAXN];

void dfs(int u, int n) {
    visited[u] = true;
    path.push_back(u);

    if(u == n) {
        cout << path.size() - 1 << endl;
        for(int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
        cout << endl;
        exit(0);
    }

    for(int v : adj[u]) {
        if(!visited[v]) {
            dfs(v, n);
        }
    }

    path.pop_back();
}

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, n);

    cout << -1 << endl;

    return 0;
}