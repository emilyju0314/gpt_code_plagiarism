#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> grid;
string actions;
int n, x0, y0;

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

bool canMove(int x, int y, char dir) {
    int dx = 0, dy = 0;
    
    if (dir == 'L') dy = -1;
    else if (dir == 'R') dy = 1;
    else if (dir == 'U') dx = -1;
    else if (dir == 'D') dx = 1;
    
    int nx = x + dx, ny = y + dy;
    
    if (valid(nx, ny)) {
        for (int k = 1; valid(x + k*dx, y + k*dy); k++) {
            if (grid[x + k*dx][y + k*dy] == 1) {
                return true;
            }
        }
    }
    
    return false;
}

void performAction(char action, int x, int y) {
    if (action == '1') {
        grid[x][y] = 1;
        actions += "1";
    } else if (action == '2') {
        grid[x][y] = 0;
        actions += "2";
    } else {
        actions += action;
    }
}

bool simulate() {
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    char dir[] = {'L', 'R', 'U', 'D'};
    
    stack<pair<int, int>> s;
    s.push({x0 - 1, y0 - 1});
    
    while (!s.empty()) {
        pair<int, int> p = s.top();
        s.pop();
        int x = p.first, y = p.second;
        
        performAction('1', x, y);
        
        for (int i = 0; i < 4; i++) {
            if (canMove(x, y, dir[i])) {
                int nx = x + dx[i], ny = y + dy[i];
                if (grid[nx][ny] == 1) {
                    s.push({nx, ny});
                    performAction(dir[i], x, y);
                    break;
                }
            }
        }
    }
    
    return grid[x0 - 1][y0 - 1] == 0;
}

int main() {
    cin >> n >> x0 >> y0;
    
    grid.resize(n, vector<int>(n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    
    if (simulate()) {
        cout << "YES" << endl;
        cout << actions << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}