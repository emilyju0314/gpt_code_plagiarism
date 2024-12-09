#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> adj;
vector<int> subtree_size;
vector<int> depth;
vector<int> mex_count;
int n;

int dfs(int node, int parent) {
    subtree_size[node] = 1;
    for (int neighbor : adj[node]) {
        if (neighbor != parent) {
            depth[neighbor] = depth[node] + 1;
            subtree_size[node] += dfs(neighbor, node);
        }
    }
    return subtree_size[node];
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        adj.assign(n, vector<int>());
        subtree_size.assign(n, 0);
        depth.assign(n, 0);
        mex_count.assign(n+1, 0);

        for (int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0, -1);

        for (int i = 0; i < n; i++) {
            mex_count[min(subtree_size[i], n - subtree_size[i])]++;
        }

        int s = 0, total = n-1;
        for (int k = 0; k <= n; k++) {
            while (s < n && total >= s) {
                total -= subtree_size[s];
                s++;
            }
            cout << total + 1 << " ";
            total += mex_count[k];
        }
        cout << endl;
    }

    return 0;
}