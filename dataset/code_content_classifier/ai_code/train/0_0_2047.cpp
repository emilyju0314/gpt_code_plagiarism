#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> depth;
vector<double> ans;

void dfs(int node, int parent, int d) {
    depth[node] = d;
    ans[1] = d;
    for (int child : adj[node]) {
        if (child != parent) {
            dfs(child, node, d + 1);
            ans[node] += ans[child] / adj[node].size();
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    adj.resize(n + 1);
    depth.resize(n + 1);
    ans.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, 0);

    cout << fixed;
    cout.precision(15);
    cout << ans[1] << endl;

    return 0;
}