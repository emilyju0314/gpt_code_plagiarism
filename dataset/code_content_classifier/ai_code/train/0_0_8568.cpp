#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canCycle(vector<vector<int>>& graph, int n) {
    vector<bool> visited(n+1, false);
    visited[1] = true;
    
    for (int i = 2; i <= n; i++) {
        if (graph[1][i] == 1) {
            visited[i] = true;
            for (int j = 2; j <= n; j++) {
                if (graph[i][j] == 1 && visited[j] && j != 1) {
                    return true;
                }
            }
        }
    }
    
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> graph(n+1, vector<int>(n+1, 0));
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = graph[b][a] = 1;
        
        if (canCycle(graph, n)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}