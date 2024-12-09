#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[200005];
vector<int> color(200005, -1);
vector<int> ans;

bool dfs(int v, int p, int c) {
    color[v] = c;
    for (int u : adj[v]) {
        if (u == p) continue;
        if (color[u] == -1) {
            if (!dfs(u, v, 1 - c))
                return false;
        } else if (color[u] == color[v]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (!dfs(0, -1, 0)) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int i = 0; i < m; i++) {
            ans.push_back(color[adj[i][0]] == 1 ? 0 : 1);
        }
        for (int a : ans) {
            cout << a;
        }
    }

    return 0;
}