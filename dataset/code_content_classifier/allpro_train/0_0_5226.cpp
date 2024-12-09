#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void dfs(vector<vector<int>>& adj_list, vector<bool>& visited, int node) {
    visited[node] = true;
    for (int neighbor : adj_list[node]) {
        if (!visited[neighbor]) {
            dfs(adj_list, visited, neighbor);
        }
    }
}

int countConnectedComponents(vector<vector<int>>& adj_list) {
    int n = adj_list.size();
    vector<bool> visited(n, false);
    int num_connected_components = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            num_connected_components++;
            dfs(adj_list, visited, i);
        }
    }
    return num_connected_components;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj_list(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj_list[x-1].push_back(y-1);
        adj_list[y-1].push_back(x-1);
    }
    
    int k;
    cin >> k;
    vector<int> results;
    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        
        vector<bool> removed_edges(m, false);
        for (int j = l-1; j < r; j++) {
            removed_edges[j] = true;
        }
        
        vector<vector<int>> experiment_adj_list = adj_list;
        for (int j = 0; j < m; j++) {
            if (removed_edges[j]) {
                int x = adj_list[j][0];
                int y = adj_list[j][1];
                
                vector<int>& neighbors_x = experiment_adj_list[x];
                neighbors_x.erase(remove(neighbors_x.begin(), neighbors_x.end(), y), neighbors_x.end());
                
                vector<int>& neighbors_y = experiment_adj_list[y];
                neighbors_y.erase(remove(neighbors_y.begin(), neighbors_y.end(), x), neighbors_y.end());
            }
        }
        
        int num_connected_components = countConnectedComponents(experiment_adj_list);
        results.push_back(num_connected_components);
    }
    
    for (int result : results) {
        cout << result << "\n";
    }
    
    return 0;
}