#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool canReachEnd(int x, int y, vector<string>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    
    if (x < 0 || x >= rows || y < 0 || y >= cols || grid[x][y] == '%') {
        return false;
    }
    
    if (grid[x][y] == '@') {
        return true;
    }
    
    grid[x][y] = '%';
    
    return canReachEnd(x + 1, y, grid) || canReachEnd(x - 1, y, grid) || canReachEnd(x, y + 1, grid) || canReachEnd(x, y - 1, grid);
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    
    int startX = -1, startY = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '$') {
                startX = i;
                startY = j;
            }
        }
    }
    
    if (canReachEnd(startX, startY, grid)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}