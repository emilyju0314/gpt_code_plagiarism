#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

struct State {
    int x, y, steps;
};

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int solve(vector<vector<char>>& grid, pair<int, int> hero) {
    int w = grid[0].size();
    int h = grid.size();
    
    vector<vector<vector<vector<bool>>> visited(h, vector<vector<vector<bool>>>(w, vector<vector<bool>>(h, vector<bool>(w, false))));
    
    queue<State> q;
    q.push({hero.first, hero.second, 0});
    
    while (!q.empty()) {
        State curr = q.front();
        q.pop();
        
        if (grid[curr.y][curr.x] == '*') {
            grid[curr.y][curr.x] = '.';
        }
        
        if (grid[curr.y][curr.x] == '_') {
            return curr.steps;
        }
        
        if (visited[curr.y][curr.x][curr.y][curr.x]) {
            continue;
        }
        
        visited[curr.y][curr.x][curr.y][curr.x] = true;
        
        for (int i = 0; i < 4; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];
            
            if (nx >= 0 && nx < w && ny >= 0 && ny < h && grid[ny][nx] != '#') {
                if (grid[ny][nx] == '*' && (nx + dx[i] >= 0 && nx + dx[i] < w && ny + dy[i] >= 0 && ny + dy[i] < h && grid[ny + dy[i]][nx + dx[i]] == '.')) {
                    q.push({nx, ny, curr.steps + 2});
                } else {
                    q.push({nx, ny, curr.steps + 1});
                }
            }
        }
    }
    
    return -1;
}

int main() {
    int w, h;
    while (true) {
        cin >> w >> h;
        if (w == 0 && h == 0) {
            break;
        }
        vector<vector<char>> grid(h, vector<char>(w));
        pair<int, int> hero;
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == '@') {
                    hero = {j, i};
                }
            }
        }
        
        cout << solve(grid, hero) << endl;
    }
    
    return 0;
}