#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<vector<int>>& graph, int n, int m, int i, int j, int color) {
    // Check if any adjacent vertex has the same color
    if (i > 0 && graph[i-1][j] == color) return false;
    if (i < n - 1 && graph[i+1][j] == color) return false;
    if (j > 0 && graph[i][j-1] == color) return false;
    if (j < m - 1 && graph[i][j+1] == color) return false;
    
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> graph(n, vector<int>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            graph[i][j] = c - '0';
        }
    }
    
    vector<int> colors = {1, 2, 3, 4};
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 0) {
                for (int color : colors) {
                    if (isValid(graph, n, m, i, j, color)) {
                        graph[i][j] = color;
                        break;
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << graph[i][j];
        }
        cout << endl;
    }
    
    return 0;
}