#include <iostream>
#include <vector>

using namespace std;

int n, m, p;
vector<int> speeds;
vector<vector<char>> grid;
vector<vector<bool>> visited;

int expand(int player, int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == '#' || grid[x][y] != '.') {
        return 0;
    }
    
    visited[x][y] = true;
    grid[x][y] = (char)('0' + player);
    
    int cnt = 1;
    cnt += expand(player, x-1, y);
    cnt += expand(player, x+1, y);
    cnt += expand(player, x, y-1);
    cnt += expand(player, x, y+1);
    
    return cnt;
}

int main() {
    cin >> n >> m >> p;
    
    speeds.resize(p);
    for (int i = 0; i < p; i++) {
        cin >> speeds[i];
    }
    
    grid.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m, false));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    
    bool changed = true;
    while (changed) {
        changed = false;
        
        for (int player = 1; player <= p; player++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == (char)('0' + player) && !visited[i][j]) {
                        visited[i][j] = true;
                        if (expand(player, i, j) > 1) {
                            changed = true;
                        }
                    }
                }
            }
        }
    }
    
    vector<int> cellCount(p, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != '.' && grid[i][j] != '#') {
                int player = grid[i][j] - '0';
                cellCount[player-1]++;
            }
        }
    }
    
    for (int i = 0; i < p; i++) {
        cout << cellCount[i] << " ";
    }
    cout << endl;
    
    return 0;
}