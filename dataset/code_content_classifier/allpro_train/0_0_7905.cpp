#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 3e5+5;

int n;
int a[MAXN];
vector<int> adj[MAXN];
vector<pair<int, int>> edges;
vector<int> dfs_order;
int order = 0;

void dfs(int u) {
    order++;
    dfs_order.push_back(u);
    for (int v : adj[u]) {
        dfs(v);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        edges.push_back({u, v});
    }

    dfs(1);

    vector<int> original_labeling(n + 1);

    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;

        if (a[u] < a[v]) {
            swap(original_labeling[a[u]], original_labeling[a[v]]);
        }
    }

    bool possible = true;
    for (int i = 1; i <= n; i++) {
        if (original_labeling[i] == 0) {
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << "YES\n";
        cout << order << endl;
        for (int i = 1; i <= n; i++) {
            cout << original_labeling[i] << " ";
        }
        cout << endl;
    } else {
        cout << "NO\n";
    }

    return 0;
}