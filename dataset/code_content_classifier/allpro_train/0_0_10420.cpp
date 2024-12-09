#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<char>> grid;
vector<vector<bool>> visited;

bool isInside(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

void markUnreachable(int r, int c) {
    queue<pair<int, int>> q;
    q.push({r, c});
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if (visited[x][y]) continue;
        
        visited[x][y] = true;
        
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            
            if (isInside(newX, newY) && grid[newX][newY] == '#' && !visited[newX][newY]) {
                q.push({newX, newY});
            }
        }
    }
}

int minDeletions() {
    int deletions = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '#') {
                visited.assign(n, vector<bool>(m, false));
                visited[i][j] = true;
                markUnreachable(i, j);
                
                bool flag = false;
                
                for (int x = 0; x < n; x++) {
                    for (int y = 0; y < m; y++) {
                        if (!visited[x][y] && grid[x][y] == '#') {
                            flag = true;
                            break;
                        }
                    }
                    if (flag) break;
                }
                
                if (flag) {
                    deletions++;
                }
            }
        }
    }
    
    return deletions;
}

int main() {
    cin >> n >> m;
    
    grid.resize(n, vector<char>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    
    int result = minDeletions();
    
    cout << result << endl;
    
    return 0;
}