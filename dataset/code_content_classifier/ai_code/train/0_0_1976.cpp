#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj_list;
vector<int> depth;
vector<int> parent;

void dfs(int node, int par, int d) {
    depth[node] = d;
    parent[node] = par;
    
    for (int child : adj_list[node]) {
        if (child != par) {
            dfs(child, node, d + 1);
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    adj_list.resize(n + 1);
    depth.resize(n + 1);
    parent.resize(n + 1);
    
    for (int i = 0; i < n - 1; i++) {
        int p, q;
        cin >> p >> q;
        adj_list[p].push_back(q);
        adj_list[q].push_back(p);
    }
    
    dfs(1, 0, 0);
    
    int max_depth = 0, farthest_node = 1;
    
    for (int i = 1; i <= n; i++) {
        if (depth[i] > max_depth) {
            max_depth = depth[i];
            farthest_node = i;
        }
    }
    
    dfs(farthest_node, 0, 0);
    
    max_depth = 0;
    
    for (int i = 1; i <= n; i++) {
        if (depth[i] > max_depth) {
            max_depth = depth[i];
        }
    }
    
    cout << max_depth + 1 << endl;
    
    return 0;
}