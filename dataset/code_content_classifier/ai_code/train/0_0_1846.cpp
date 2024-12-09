#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<bool>> visited;
vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isValid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs(vector<vector<char>> &grid, int x, int y, int &count) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        
        for (auto dir : dirs) {
            int nx = cx + dir.first;
            int ny = cy + dir.second;
            
            if (isValid(nx, ny, grid.size(), grid[0].size()) && grid[nx][ny] == '#' && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
                count++;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<char>> grid(n, vector<char>(m));
    visited = vector<vector<bool>>(n, vector<bool>(m, false));
    
    int paintedCount = 0;
    pair<int, int> start;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == '#') {
                paintedCount++;
                start = {i, j};
            }
        }
    }
    
    int totalCount = paintedCount;
    
    bfs(grid, start.first, start.second, paintedCount);
    
    if (paintedCount < totalCount - 1) {
        cout << 0 << endl; // Already disconnected
    } else {
        int minDeleted = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '#') {
                    grid[i][j] = '.';
                    visited = vector<vector<bool>>(n, vector<bool>(m, false));
                    paintedCount = 0;
                    bfs(grid, start.first, start.second, paintedCount);
                    
                    if (paintedCount < totalCount - 1) {
                        minDeleted++;
                        cout << minDeleted << endl;
                        return 0;
                    }
                    
                    grid[i][j] = '#'; // Revert back
                }
            }
        }
        
        cout << -1 << endl; // Can't make it disconnected
    }
    
    return 0;
}