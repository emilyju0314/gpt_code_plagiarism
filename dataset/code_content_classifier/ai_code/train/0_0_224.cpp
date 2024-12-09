#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<vector<int>> adj;
vector<pair<int, int>> edges;
vector<int> tin, fup, used;
int timer = 0;
set<int> bridges;

void dfs(int v, int p = -1) {
    used[v] = 1;
    tin[v] = fup[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (used[to]) {
            fup[v] = min(fup[v], tin[to]);
        } else {
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            if (fup[to] > tin[v]) {
                bridges.insert(edges[to].first);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n+1);
    tin.resize(n+1);
    fup.resize(n+1);
    used.resize(n+1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(i);
        adj[v].push_back(i);
        edges.push_back({u, v});
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }

    set<int> result;
    for (int i = 0; i < m; i++) {
        if (bridges.count(i)) {
            result.insert(i);
        }
    }

    cout << result.size() << endl;
    for (int edge : result) {
        cout << edge+1 << " ";
    }

    return 0;
}