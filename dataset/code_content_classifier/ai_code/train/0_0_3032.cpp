#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> BFS(const vector<vector<int>>& adj_list, int start) {
    vector<int> dist(adj_list.size(), -1);
    queue<int> q;
    
    q.push(start);
    dist[start] = 0;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (int neighbor : adj_list[node]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }
    
    return dist;
}

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    
    vector<vector<int>> adj_list(N + 1);
    
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    
    for (int q = 0; q < Q; q++) {
        int a, b;
        cin >> a >> b;
        
        vector<int> dist_start = BFS(adj_list, a);
        int min_hyperspace_highways = dist_start[b];
        
        cout << min_hyperspace_highways << endl;
    }
    
    return 0;
}