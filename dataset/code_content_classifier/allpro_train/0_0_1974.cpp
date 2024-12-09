#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> graph(N+1);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    vector<bool> visited(N+1, false);
    queue<int> q;
    q.push(1);
    visited[1] = true;
    
    int edges_added = 0;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                edges_added++;
            }
        }
    }
    
    cout << edges_added << endl;
    
    return 0;
}