#include <iostream>
#include <vector>
using namespace std;

int find_min_operations(vector<vector<int>>& grid, int n, int m) {
    int min_operations = 0;
    for(int i = 1; i < n-1; i++) {
        for(int j = 1; j < m-1; j++) {
            if(grid[i][j] == 0) {
                min_operations++;
                grid[i][j] = 1;
                for(int x = i+1; x < n-1; x++) {
                    if(grid[x][1] == 0) {
                        min_operations++;
                        grid[x][1] = 1;
                    }
                    if(grid[x][m-2] == 0) {
                        min_operations++;
                        grid[x][m-2] = 1;
                    }
                }
                for(int y = j+1; y < m-1; y++) {
                    if(grid[1][y] == 0) {
                        min_operations++;
                        grid[1][y] = 1;
                    }
                    if(grid[n-2][y] == 0) {
                        min_operations++;
                        grid[n-2][y] = 1;
                    }
                }
            }
        }
    }
    return min_operations;
}

int main() {
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<int>> grid(n, vector<int>(m, 0));
        for(int j = 0; j < n; j++) {
            string row;
            cin >> row;
            for(int k = 0; k < m; k++) {
                grid[j][k] = row[k] - '0';
            }
        }
        
        int min_operations = find_min_operations(grid, n, m);
        cout << min_operations << endl;
    }
    
    return 0;
}