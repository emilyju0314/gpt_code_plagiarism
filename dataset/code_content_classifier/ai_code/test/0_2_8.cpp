#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
int illusion[MAXN];
int subtree_illusion_sum[MAXN];
int subtree_min_energy[MAXN];

void dfs(int u, int parent) {
    subtree_illusion_sum[u] = illusion[u];
    subtree_min_energy[u] = 0;

    for(int v : adj[u]) {
        if(v != parent) {
            dfs(v, u);
            subtree_illusion_sum[u] += subtree_illusion_sum[v];
            subtree_min_energy[u] += subtree_min_energy[v] + max(abs(illusion[u] - illusion[v]), abs(illusion[u] + illusion[v]));
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n; i++) {
        cin >> illusion[i];
    }

    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    while(q--) {
        int type, u, v, c;
        cin >> type >> u >> v;

        if(type == 1) {
            cin >> c;
            illusion[u] = c;
            dfs(1, 0);
        } else {
            cout << subtree_min_energy[u] - subtree_min_energy[v] << endl;
        }
    }

    return 0;
}