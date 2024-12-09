#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>>& adjList, vector<bool>& visited, vector<int>& match, int u) {
    for (int v : adjList[u]) {
        if (!visited[v]) {
            visited[v] = true;
            if (match[v] == -1 || dfs(adjList, visited, match, match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int maxMatching(vector<vector<int>>& adjList, int n, int m) {
    vector<int> match(m, -1);
    int count = 0;
    for (int u = 0; u < n; u++) {
        vector<bool> visited(m, false);
        if (dfs(adjList, visited, match, u)) {
            count++;
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<int>> adjList(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            adjList[i].push_back(x-1);
            adjList[i].push_back(y-1);
        }
        
        int matching = maxMatching(adjList, n, m);
        
        if (matching == n) {
            cout << "YES" << endl;
            for (int i = 0; i < m; i++) {
                if (adjList[matching][i] != -1) {
                    cout << matching+1 << " " << adjList[matching][i]+1 << endl;
                }
            }
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}