#include <iostream>
#include <string>
#include <vector>

using namespace std;

int countIslands(vector<vector<int>>& grid, int x, int y) {
    if (x < 0 || x >= 12 || y < 0 || y >= 12 || grid[x][y] == 0) {
        return 0;
    }

    grid[x][y] = 0;

    countIslands(grid, x + 1, y);
    countIslands(grid, x - 1, y);
    countIslands(grid, x, y + 1);
    countIslands(grid, x, y - 1);

    return 1;
}

int main() {
    string line;
    while (getline(cin, line)) {
        if (line.empty()) {
            break;
        }

        vector<vector<int>> grid(12, vector<int>(12));

        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 12; j++) {
                grid[i][j] = line[j] - '0';
            }
            if (i != 11) {
                getline(cin, line);
            }
        }

        int islandCount = 0;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 12; j++) {
                if (grid[i][j] == 1) {
                    islandCount += countIslands(grid, i, j);
                }
            }
        }

        cout << islandCount << endl;
    }

    return 0;
}