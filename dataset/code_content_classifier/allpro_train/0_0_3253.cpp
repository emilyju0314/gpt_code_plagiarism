#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<int> subtree_sizes, ans;
int n;

void dfs(int v, int p) {
    subtree_sizes[v] = 1;
    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v);
            subtree_sizes[v] += subtree_sizes[u];
        }
    }
}

void solve(int v, int p) {
    ans[v] = subtree_sizes[v]; // Initial answer for the node v
    for (int u : adj[v]) {
        if (u != p) {
            int prev_v_size = subtree_sizes[v];
            int prev_u_size = subtree_sizes[u];
    
            subtree_sizes[v] -= subtree_sizes[u];
            subtree_sizes[u] += subtree_sizes[v];
    
            solve(u, v);
    
            subtree_sizes[v] = prev_v_size;
            subtree_sizes[u] = prev_u_size;
        }
    }
}

int main() {
    cin >> n;
    adj.resize(n);
    subtree_sizes.resize(n);
    ans.resize(n);

    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        
        if (p != 0) { // If not the root node
            p--; // Convert 1-based index to 0-based index
            adj[i].push_back(p);
            adj[p].push_back(i);
        }
    }

    dfs(0, -1); // Perform DFS to calculate subtree sizes
    solve(0, -1); // Solve for each node

    for (int a : ans) {
        cout << a << endl;
    }

    return 0;
}