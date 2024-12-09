#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> leaves;
vector<int> depth;
int n;

void dfs(int v, int p, int d) {
    depth[v] = d;
    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v, d + 1);
        }
    }
    if (adj[v].size() == 1) {
        leaves.push_back(v);
    }
}

int main() {
    cin >> n;
    adj.resize(n + 1);
    depth.resize(n + 1);

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int root = 1;
    while (adj[root].size() == 1) {
        root++;
    }

    dfs(root, 0, 0);

    int min_f = 0, max_f = 0;
    
    for (int leaf : leaves) {
        if (depth[leaf] % 2 == 0) {
            min_f = max(min_f, 2);
            max_f += 1;
        } else {
            min_f = max(min_f, 1);
            max_f += 1;
        }
    }

    cout << min_f << " " << max_f << endl;

    return 0;
}