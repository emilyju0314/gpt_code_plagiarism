#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

const int MAXN = 4e5 + 5;

vector<int> colors(MAXN);
vector<vector<int>> adj(MAXN);
vector<unordered_set<int>> colorSet(MAXN);

void dfs(int v, int p) {
    colorSet[v].insert(colors[v]);
    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v);
            colorSet[v].insert(colorSet[u].begin(), colorSet[u].end());
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> colors[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 0);

    for (int i = 0; i < m; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int v, c;
            cin >> v >> c;
            colors[v] = c;
            colorSet[v].clear();
            dfs(v, 0);
        } else {
            int v;
            cin >> v;
            cout << colorSet[v].size() << endl;
        }
    }

    return 0;
}