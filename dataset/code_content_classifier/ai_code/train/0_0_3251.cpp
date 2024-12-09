#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int N = 2e5+5;

int n, m, s, t, ds, dt;
vector<int> adj[N];
int deg[N];

void dfs(int v, int p) {
    for (int u : adj[v]) {
        if (u != p) {
            deg[v]++;
            deg[u]++;
            if (deg[v] <= ds && deg[u] <= dt) {
                cout << v << " " << u << endl;
                dfs(u, v);
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin >> s >> t >> ds >> dt;

    cout << "Yes" << endl;
    dfs(s, -1);

    return 0;
}