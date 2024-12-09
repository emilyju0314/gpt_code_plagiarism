#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int calculateMinClimbs(int n, int m, vector<vector<char>>& castleSketch) {
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<pair<int, int>> q;
    
    // Find the starting position of the ninja
    int startX = -1, startY = -1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (castleSketch[i][j] == '&') {
                startX = i;
                startY = j;
                break;
            }
        }
    }
    
    // Perform BFS to find the minimum number of climbs
    q.push({startX, startY});
    visited[startX][startY] = true;
    vector<int> dirX = {1, -1, 0, 0};
    vector<int> dirY = {0, 0, 1, -1};
    int climbs = 0;
    
    while (!q.empty()) {
        int size = q.size();
        
        for (int i = 0; i < size; i++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            // Check all adjacent positions
            for (int j = 0; j < 4; j++) {
                int newX = x + dirX[j];
                int newY = y + dirY[j];
                
                if (newX >= 0 && newX < m && newY >= 0 && newY < n && !visited[newX][newY]) {
                    if (castleSketch[newX][newY] == '#') {
                        climbs++;
                        visited[newX][newY] = true;
                    } else {
                        q.push({newX, newY});
                        visited[newX][newY] = true;
                    }
                }
            }
        }
    }
    
    return climbs;
}

int main() {
    int n, m;
    
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }
        
        vector<vector<char>> castleSketch(m, vector<char>(n));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> castleSketch[i][j];
            }
        }
        
        int minClimbs = calculateMinClimbs(n, m, castleSketch);
        cout << minClimbs << endl;
    }
    
    return 0;
}