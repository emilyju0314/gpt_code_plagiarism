#include <iostream>
#include <vector>

using namespace std;

int m, n;
vector<vector<int>> ice;
vector<vector<bool>> visited;

int dfs(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m || !ice[i][j] || visited[i][j]) {
        return 0;
    }
    
    visited[i][j] = true;
    
    int count = 1;
    
    count += dfs(i+1, j);
    count += dfs(i-1, j);
    count += dfs(i, j+1);
    count += dfs(i, j-1);
    
    return count;
}

int main() {
    while (true) {
        cin >> m >> n;
        
        if (m == 0 && n == 0) {
            break;
        }
        
        ice.assign(n, vector<int>(m, 0));
        visited.assign(n, vector<bool>(m, false));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> ice[i][j];
            }
        }
        
        int maxCount = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (ice[i][j] && !visited[i][j]) {
                    maxCount = max(maxCount, dfs(i, j));
                }
            }
        }
        
        cout << maxCount << endl;
    }
    
    return 0;
}