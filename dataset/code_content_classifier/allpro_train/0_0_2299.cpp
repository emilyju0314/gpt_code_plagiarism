#include <iostream>
#include <vector>

using namespace std;

int n, m;

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited, int& size) {
    if(isValid(x, y) && !visited[x][y] && grid[x][y] == 0) {
        visited[x][y] = true;
        size++;
        dfs(x-1, y, grid, visited, size);
        dfs(x+1, y, grid, visited, size);
        dfs(x, y-1, grid, visited, size);
        dfs(x, y+1, grid, visited, size);
    }
}

int main() {
    cin >> n >> m;

    vector<vector<char>> field(n, vector<char>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> field[i][j];
        }
    }

    vector<vector<int>> grid(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(field[i][j] == '*') {
                grid[i][j] = -1;
            }
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 0 && !visited[i][j]) {
                int size = 0;
                dfs(i, j, grid, visited, size);
                for(int x = 0; x < n; x++) {
                    for(int y = 0; y < m; y++) {
                        if(visited[x][y]) {
                            grid[x][y] = size;
                        }
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(field[i][j] == '*') {
                cout << grid[i][j] % 10;
            } else {
                cout << '.';
            }
        }
        cout << endl;
    }

    return 0;
}