#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    vector<int> in_degree(n+1, 0);
    vector<int> labels(n+1, 0);
    vector<bool> visited(n+1, false);

    for(int i=0; i<m; i++) {
        int v, u;
        cin >> v >> u;
        adj[v].push_back(u);
        in_degree[u]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=1; i<=n; i++) {
        if(in_degree[i] == 0) {
            pq.push(i);
        }
    }

    int label = 1;
    while(!pq.empty()) {
        int node = pq.top();
        pq.pop();
        labels[node] = label++;
        
        for(int neighbor : adj[node]) {
            in_degree[neighbor]--;
            if(in_degree[neighbor] == 0 && !visited[neighbor]) {
                pq.push(neighbor);
            }
        }
        visited[node] = true;
    }

    for(int i=1; i<=n; i++) {
        cout << labels[i] << " ";
    }

    return 0;
}