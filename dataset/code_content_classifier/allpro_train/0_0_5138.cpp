#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;

vector<int> adj[MAXN];
int nodeValues[MAXN];
int subtreeValues[MAXN];

void dfs(int u, int parent, int dist) {
    subtreeValues[u] += nodeValues[u];
    
    for (int v : adj[u]) {
        if (v != parent) {
            dfs(v, u, dist + 1);
            subtreeValues[u] += subtreeValues[v];
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    while (q--) {
        int t;
        cin >> t;

        if (t == 0) {
            int v, x, d;
            cin >> v >> x >> d;

            dfs(v, -1, 0);

            for (int i = 1; i <= n; i++) {
                nodeValues[i] += (dist[i] <= d ? x : 0);
                subtreeValues[i] = 0;
            }
        } else {
            int v;
            cin >> v;
            dfs(v, -1, 0);
            cout << nodeValues[v] + subtreeValues[v] << endl;
            subtreeValues[v] = 0;
        }
    }

    return 0;
}