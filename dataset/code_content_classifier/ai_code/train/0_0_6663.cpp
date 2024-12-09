#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<int>> graph(n, vector<int>(n, INT_MAX));
    
    for(int i = 0; i < m; i++) {
        int u, v, l, d;
        cin >> u >> v >> l >> d;
        graph[u - 1][v - 1] = l;
        graph[v - 1][u - 1] = l;
    }
    
    for(int i = 0; i < n; i++) {
        graph[i][i] = 0;
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int t = 0; t < n; t++) {
                if(t != i && t != j) {
                    graph[i][j] = min(graph[i][j], graph[i][t] + graph[t][j]);
                }
            }
        }
    }
    
    cout << graph[0][n - 1] * k << endl;
    
    return 0;
}