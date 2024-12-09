#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, k;
vector<string> grid;
vector<vector<bool>> visited;

int dfs(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= n || grid[r][c] == 'X' || visited[r][c]) {
        return 0;
    }
    
    visited[r][c] = true;
    int size = 1;
    
    size += dfs(r+1, c);
    size += dfs(r-1, c);
    size += dfs(r, c+1);
    size += dfs(r, c-1);
    
    return size;
}

int main() {
    cin >> n >> k;
    
    grid.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    
    int maxComponentSize = 0;
    
    for (int i = 0; i <= n-k; i++) {
        for (int j = 0; j <= n-k; j++) {
            visited.assign(n, vector<bool>(n, false));
            
            for (int x = i; x < i+k; x++) {
                for (int y = j; y < j+k; y++) {
                    grid[x][y] = '.';
                }
            }
            
            int componentSize = 0;
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    componentSize = max(componentSize, dfs(x, y));
                }
            }
            
            maxComponentSize = max(maxComponentSize, componentSize);
            
            for (int x = i; x < i+k; x++) {
                for (int y = j; y < j+k; y++) {
                    grid[x][y] = 'X';
                }
            }
        }
    }
    
    cout << maxComponentSize << endl;
    
    return 0;
}