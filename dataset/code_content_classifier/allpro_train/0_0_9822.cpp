#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    vector<pair<int, int>> blackCells;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'B') {
                blackCells.push_back({i, j});
            }
        }
    }

    int minX = n, maxX = -1, minY = m, maxY = -1;
    for(auto cell : blackCells) {
        int x = cell.first;
        int y = cell.second;
        
        minX = min(minX, x);
        maxX = max(maxX, x);
        minY = min(minY, y);
        maxY = max(maxY, y);
    }

    for(auto cell : blackCells) {
        int x = cell.first;
        int y = cell.second;

        if(x < minX || x > maxX || y < minY || y > maxY) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}