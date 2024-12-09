#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>>& adjList, int start, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adjList[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adjList(n);
    for (int i = 0; i < m; i++) {
        int s, t;
        cin >> s >> t;
        adjList[s].push_back(t);
        adjList[t].push_back(s);
    }
    
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int s, t;
        cin >> s >> t;
        
        vector<bool> visited(n, false);
        bfs(adjList, s, visited);
        
        if (visited[t]) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    
    return 0;
}