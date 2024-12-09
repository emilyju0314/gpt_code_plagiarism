#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAXN = 1e5 + 5;

int n, q;
vector<int> illusion_rate(MAXN);
vector<vector<int>> adj_list(MAXN);
vector<long long> subtree_energy(MAXN);

void dfs(int node, int parent) {
    subtree_energy[node] = 0;
    
    for (int child : adj_list[node]) {
        if (child != parent) {
            subtree_energy[child] = subtree_energy[node] + max(abs(illusion_rate[node] + illusion_rate[child]), abs(illusion_rate[node] - illusion_rate[child]));
            dfs(child, node);
        }
    }
}

int main() {
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> illusion_rate[i];
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    dfs(1, 0);

    for (int i = 0; i < q; i++) {
        int type, u, v;
        cin >> type >> u >> v;

        if (type == 1) {
            illusion_rate[u] = v;
            dfs(1, 0);
        } else if (type == 2) {
            cout << subtree_energy[u] - subtree_energy[v] << endl;
        }
    }

    return 0;
}