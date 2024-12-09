#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<vector<int>> adj;
vector<int> subtree_sizes;
double total_weight = 0;

void dfs(int v, int parent) {
    subtree_sizes[v] = 1;
    for (int u : adj[v]) {
        if (u != parent) {
            dfs(u, v);
            subtree_sizes[v] += subtree_sizes[u];
            total_weight += (double)subtree_sizes[u] * (adj.size() - subtree_sizes[u]);
        }
    }
}

int main() {
    int n, s;
    cin >> n >> s;

    adj.resize(n);
    subtree_sizes.resize(n);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, -1);

    cout << fixed << setprecision(15) << (2 * total_weight) / (double)n << endl;

    return 0;
}