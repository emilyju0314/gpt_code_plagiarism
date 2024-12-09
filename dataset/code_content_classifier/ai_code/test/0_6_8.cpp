#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

vector<int> adj[MAXN];
int a[MAXN];

int dfs(int u, int parent, int target, int energy) {
    int min_energy = abs(a[u] - a[target]);
    for (int v : adj[u]) {
        if (v != parent) {
            min_energy = min(min_energy, dfs(v, u, target, max(energy, abs(a[u] - a[v])));
        }
    }
    return min_energy;
}

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < q; i++) {
        int query, u, v;
        cin >> query >> u >> v;
        if (query == 1) {
            a[u] = v;
        } else {
            cout << dfs(u, -1, v, 0) << endl;
        }
    }

    return 0;
}