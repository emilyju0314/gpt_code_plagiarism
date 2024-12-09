#include <iostream>
#include <vector>

using namespace std;

int dfs(int node, int parent, vector<vector<int>>& adj_list, int x) {
    int cnt = 0;
    for (int child : adj_list[node]) {
        if (child != parent) {
            cnt += dfs(child, node, adj_list, x);
        }
    }
    return (node == x ? cnt + 1 : cnt);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;

        vector<vector<int>> adj_list(n+1);

        for (int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v;
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }

        if (dfs(x, -1, adj_list, x) <= 1) {
            cout << "Ashish" << endl;
        } else {
            cout << "Ayush" << endl;
        }
    }

    return 0;
}