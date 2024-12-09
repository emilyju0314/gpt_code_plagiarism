#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int curr_label = 0;

void dfs(int node, int parent, const vector<vector<int>>& adj, vector<int>& labels) {
    for(int child : adj[node]) {
        if(child != parent) {
            labels.push_back(curr_label);
            curr_label++;
            dfs(child, node, adj, labels);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--; // 0-based indexing
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> labels;
    dfs(0, -1, adj, labels);

    for(int i = 0; i < n-1; i++) {
        cout << labels[i] << endl;
    }

    return 0;
}