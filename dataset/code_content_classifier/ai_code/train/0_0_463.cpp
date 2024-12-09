#include <iostream>
#include <vector>

using namespace std;

bool isValid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(vector<vector<char>>& maze, int x, int y, vector<vector<bool>>& visited) {
    visited[x][y] = true;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    
    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (isValid(newX, newY, maze.size(), maze[0].size()) && maze[newX][newY] == '.' && !visited[newX][newY]) {
            dfs(maze, newX, newY, visited);
        }
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<char>> maze(n, vector<char>(m));
    vector<pair<int, int>> emptyCells;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == '.') {
                emptyCells.push_back({i, j});
            }
        }
    }
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    dfs(maze, emptyCells[0].first, emptyCells[0].second, visited);
    
    for (int i = 0; i < k; i++) {
        maze[emptyCells[i].first][emptyCells[i].second] = 'X';
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << maze[i][j];
        }
        cout << endl;
    }
    
    return 0;
}