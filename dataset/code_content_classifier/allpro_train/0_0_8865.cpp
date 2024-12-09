#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> values;
vector<int> updates;
vector<int> ans;

void dfs(int node, int parent, int update) {
    values[node-1] += update;
    for(int child : adj[node]) {
        if(child != parent) {
            dfs(child, node, update);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n+1);
    values.resize(n);
    updates.resize(n+1);

    for(int i = 0; i < n; i++) {
        cin >> values[i];
    }

    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 0; i < m; i++) {
        int type, x, val;
        cin >> type >> x;
        if(type == 1) {
            cin >> val;
            updates[x] += val;
            dfs(x, -1, val);
        } else {
            ans.push_back(values[x-1]);
        }
    }

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }

    return 0;
}