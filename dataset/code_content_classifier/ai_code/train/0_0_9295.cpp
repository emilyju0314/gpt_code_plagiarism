#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool isValid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool canInfiniteWalk(vector<vector<char>>& maze, int n, int m, pair<int, int> start) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    
    q.push(start);
    visited[start.first][start.second] = true;
    
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int newX = (curr.first + dx[i] + n) % n; // calculate the remainder to account for cyclic tiling
            int newY = (curr.second + dy[i] + m) % m; // calculate the remainder to account for cyclic tiling
            
            if (isValid(newX, newY, n, m) && maze[newX][newY] != '#' && !visited[newX][newY]) {
                visited[newX][newY] = true;
                q.push({newX, newY});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && maze[i][j] != '#') {
                return false;
            }
        }
    }
    
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<char>> maze(n, vector<char>(m));
    pair<int, int> start;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 'S') {
                start = {i, j};
            }
        }
    }
    
    if (canInfiniteWalk(maze, n, m, start)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}