#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int bfs(vector<vector<char>>& grid, int H, int W, pair<int, int>& start, pair<int, int>& goal) {
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    queue<tuple<int, int, int>> q;
    q.push({start.first, start.second, 0});
    
    while (!q.empty()) {
        auto [x, y, steps] = q.front();
        q.pop();
        
        if (x == goal.first && y == goal.second) {
            return steps;
        }
        
        for (const pair<int, int>& dir : directions) {
            int nx = x + dir.first;
            int ny = y + dir.second;
            
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && grid[nx][ny] != '#' && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny, steps + 1});
            }
        }
    }
    
    return -1;
}

int main() {
    int H, W;
    cin >> H >> W;
    
    vector<vector<char>> grid(H, vector<char>(W));
    pair<int, int> start, goal;
    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                start = {i, j};
            } else if (grid[i][j] == 'G') {
                goal = {i, j};
            }
        }
    }
    
    int N;
    cin >> N;
    
    int result = bfs(grid, H, W, start, goal);
    
    for (int i = 0; i < N; i++) {
        int T;
        cin >> T;
        for (int j = 0; j < H; j++) {
            for (int k = 0; k < W; k++) {
                cin >> grid[j][k];
            }
        }
        
        if (result == -1) {
            continue;
        }
        
        int temp = bfs(grid, H, W, start, goal);
        if (temp != -1) {
            result = min(result, temp);
        }
    }
    
    cout << result << endl;
    
    return 0;
}