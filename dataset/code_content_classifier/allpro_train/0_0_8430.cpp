#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 5;

int n, m;
vector<int> parent(MAXN), depth(MAXN), parentAncestor(MAXN, -1);
vector<vector<int>> adj(MAXN);

// Perform depth-first search to populate ancestors and depths
void dfs(int u, int p, int d) {
    parent[u] = p;
    depth[u] = d;

    if (p != -1) {
        parentAncestor[u] = parent[p];
    }

    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
        }
    }
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int parentIdx;
        cin >> parentIdx;
        
        if (parentIdx != 0) {
            adj[parentIdx].push_back(i);
        }
    }

    dfs(1, -1, 0);

    cin >> m;
    while (m--) {
        int v, p;
        cin >> v >> p;

        int pAncestor = parentAncestor[v];
        int dist = (pAncestor == -1) ? 0 : (depth[v] - depth[pAncestor] - 1);

        if (dist == p) {
            cout << "1 ";
        } else {
            cout << "0 ";
        }
    }

    return 0;
}