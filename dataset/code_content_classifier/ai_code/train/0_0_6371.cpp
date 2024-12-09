#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj_list;
vector<int> beavers;
vector<int> eaten;
vector<bool> visited;

int dfs(int node) {
    visited[node] = true;
    int eaten_beavers = 0;
    
    for(int neighbor : adj_list[node]) {
        if(!visited[neighbor]) {
            eaten_beavers += dfs(neighbor);
        }
    }
    
    eaten[node] = eaten_beavers + beavers[node];
    
    return eaten[node];
}

int main() {
    int n;
    cin >> n;
    
    beavers.resize(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> beavers[i];
    }
    
    adj_list.resize(n+1);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    
    int start_vertex;
    cin >> start_vertex;
    
    eaten.resize(n+1);
    visited.assign(n+1, false);
    
    int total_eaten = dfs(start_vertex);
    
    cout << total_eaten << endl;
    
    return 0;
}