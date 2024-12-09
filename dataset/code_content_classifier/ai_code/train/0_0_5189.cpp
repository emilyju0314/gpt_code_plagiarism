#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int bfs(vector<vector<char>>& grid, vector<vector<int>>& visited, pair<int, int> start, pair<int, int> end) {
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = 0;
    
    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        
        if (current == end) {
            return visited[end.first][end.second];
        }
        
        for (int i = 0; i < 4; i++) {
            int new_x = current.first + dx[i];
            int new_y = current.second + dy[i];
            
            if (new_x >= 0 && new_x < grid.size() && new_y >= 0 && new_y < grid[0].size() && grid[new_x][new_y] != '#' && visited[new_x][new_y] == -1) {
                q.push({new_x, new_y});
                visited[new_x][new_y] = visited[current.first][current.second] + 1;
            }
        }
    }
    
    return -1; // No path found
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<char>> grid(n, vector<char>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    
    pair<int, int> start, end;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 't') {
                start = {i, j};
            } else if (grid[i][j] == 'd') {
                end = {i, j};
            }
        }
    }
    
    int q;
    cin >> q;
    
    int result = 0;
    
    for (int i = 0; i < q; i++) {
        vector<vector<int>> visited(n, vector<int>(m, -1));
        int x, y;
        cin >> x >> y;
        pair<int, int> point = {x, y};
        int shortestPath = bfs(grid, visited, start, point) + bfs(grid, visited, point, end);
        
        if (shortestPath != -2) {
            result += shortestPath;
        }
    }
    
    cout << result << endl;
    
    return 0;
}