#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> tree;
vector<int> illusion_rates;
vector<int> subtree_min_energy;
vector<int> parent;

void dfs(int node, int prev_node) {
    parent[node] = prev_node;
    subtree_min_energy[node] = abs(illusion_rates[node] - illusion_rates[prev_node]);
    
    for (int child : tree[node]) {
        if (child != prev_node) {
            dfs(child, node);
            subtree_min_energy[node] += max(abs(illusion_rates[child] + illusion_rates[node]), abs(illusion_rates[child] - illusion_rates[node]));
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    tree.resize(n+1);
    illusion_rates.resize(n+1);
    subtree_min_energy.resize(n+1);
    parent.resize(n+1);

    for (int i = 1; i <= n; i++) {
        cin >> illusion_rates[i];
    }

    for (int i = 1; i < n; i++) {
        int s, t;
        cin >> s >> t;
        tree[s].push_back(t);
        tree[t].push_back(s);
    }

    dfs(1, 0);

    for (int i = 0; i < q; i++) {
        int query_type, u, v;
        cin >> query_type >> u >> v;
        
        if (query_type == 1) {
            illusion_rates[u] = v;
            dfs(1, 0);
        } else if (query_type == 2) {
            int energy_needed = 0;
            while (u != v) {
                energy_needed += max(abs(illusion_rates[u] + illusion_rates[parent[u]]), abs(illusion_rates[u] - illusion_rates[parent[u]]));
                u = parent[u];
            }
            cout << energy_needed << endl;
        }
    }

    return 0;
}