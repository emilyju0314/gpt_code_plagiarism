#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(vector<vector<int>>& grid, int i, int j) {
    int n = grid.size();
    int m = grid[0].size();
    
    if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == -1) {
        return 0;
    }
    
    grid[i][j] = -1;
    
    return 1 + dfs(grid, i-1, j) + dfs(grid, i+1, j) + dfs(grid, i, j-1) + dfs(grid, i, j+1);
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> grid(n, vector<int>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    
    vector<int> roomSizes;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != -1) {
                roomSizes.push_back(dfs(grid, i, j));
            }
        }
    }
    
    sort(roomSizes.rbegin(), roomSizes.rend());
    
    for (int size : roomSizes) {
        cout << size << " ";
    }
    
    return 0;
}