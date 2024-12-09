#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool bfs(vector<vector<int>>& adjList, vector<int>& degrees, int n, int start, vector<int>& verticesToSteal) {
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adjList[u]) {
            if (degrees[v] % 3 == 0 && !visited[v]) {
                visited[v] = true;
                q.push(v);
                verticesToSteal.push_back(v);
            }
        }
    }
    
    return (int)verticesToSteal.size() > 0 && (int)verticesToSteal.size() < n;
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        
        vector<int> degrees(n + 1, 0);
        vector<vector<int>> adjList(n + 1);

        for (int j = 0; j < m; j++) {
            int a, b;
            cin >> a >> b;
            adjList[a].push_back(b);
            adjList[b].push_back(a);
            degrees[a]++;
            degrees[b]++;
        }
        
        vector<int> verticesToSteal;
        bool found = false;
        
        for (int j = 1; j <= n; j++) {
            if (degrees[j] % 3 == 0) {
                found = bfs(adjList, degrees, n, j, verticesToSteal);
                if (found) {
                    break;
                }
            }
        }
        
        if (found) {
            cout << "Yes" << endl;
            cout << (int)verticesToSteal.size() << endl;
            for (int v : verticesToSteal) {
                cout << v << " ";
            }
            cout << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}