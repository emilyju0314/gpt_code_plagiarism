#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dfs(vector<string>& grid, int x, int y, char c) {
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != '.') {
        return 0;
    }
    
    grid[x][y] = c;

    return 1 + dfs(grid, x+1, y, c) + dfs(grid, x-1, y, c) + dfs(grid, x, y+1, c) + dfs(grid, x, y-1, c);
}

int main() {
    int w, h;
    while (cin >> w >> h && w != 0 && h != 0) {
        vector<string> grid(h);
        for (int i = 0; i < h; i++) {
            cin >> grid[i];
        }

        int blackArea = 0, whiteArea = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] == '.') {
                    int black = dfs(grid, i, j, 'B');
                    int white = dfs(grid, i, j, 'W');

                    if (black > 0 && white == 0) {
                        blackArea += black;
                    } else if (black == 0 && white > 0) {
                        whiteArea += white;
                    }
                }
            }
        }

        cout << blackArea << " " << whiteArea << endl;
    }

    return 0;
}