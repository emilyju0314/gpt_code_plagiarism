#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 1e5;
vector<int> adj[MAXN+1];
int dist[MAXN+1];

void dfs(int u, int p, int d) {
    dist[u] = d;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
        }
    }
}

int find_farthest_vertex(int start) {
    dfs(start, 0, 0);
    int max_dist = 0, farthest_vertex = start;
    for (int i = 1; i <= MAXN; i++) {
        if (dist[i] > max_dist) {
            max_dist = dist[i];
            farthest_vertex = i;
        }
    }
    return farthest_vertex;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, a, b, da, db;
        cin >> n >> a >> b >> da >> db;

        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }

        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int farthest_a = find_farthest_vertex(a);
        int dia = dist[farthest_a];
        int farthest_b = find_farthest_vertex(b);

        if (2 * da >= db || dia <= da) {
            cout << "Alice\n";
        } else if (db <= 2 * da) {
            cout << "Bob\n";
        } else {
            int d = min(dia, db);
            int leaf_dist = dia - d;
            if (d <= da || 2 * (d + 1) <= db + leaf_dist) {
                cout << "Alice\n";
            } else {
                cout << "Bob\n";
            }
        }
    }

    return 0;
}