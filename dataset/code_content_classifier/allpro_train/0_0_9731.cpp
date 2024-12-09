#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<char>> maze;
vector<vector<bool>> visited;

bool canWalkInfinitely(int startX, int startY) {
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    queue<pair<int, int>> q;
    q.push({startX, startY});
    
    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        
        for (pair<int, int> dir : directions) {
            int nextX = (current.first + dir.first + n) % n;
            int nextY = (current.second + dir.second + m) % m;
            
            if (maze[nextX][nextY] == '#' || visited[nextX][nextY]) {
                continue;
            }
            
            visited[nextX][nextY] = true;
            q.push({nextX, nextY});
        }
    }
    
    // Check if any passable cell remains unvisited
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == '.' && !visited[i][j]) {
                return false;
            }
        }
    }
    
    return true;
}

int main() {
    cin >> n >> m;
    
    maze.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m, false));
    
    int startX, startY;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 'S') {
                startX = i;
                startY = j;
            }
        }
    }
    
    if (canWalkInfinitely(startX, startY)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}