#include <iostream>
#include <vector>

using namespace std;

bool isValid(int i, int j, int n, int m) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void connectEmptyCells(vector<string>& grid, int n, int m) {
    vector<pair<int, int>> emptyCells;

    // Identify all empty cells
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'X') {
                emptyCells.push_back({i, j});
            }
        }
    }

    // Remove some sunflowers to connect empty cells
    if (emptyCells.size() > 1) {
        for (int i = 1; i < emptyCells.size(); i++) {
            if (emptyCells[i].first == emptyCells[i - 1].first) {
                // Same row, fill the cells in between
                for (int j = emptyCells[i - 1].second + 1; j < emptyCells[i].second; j++) {
                    grid[emptyCells[i].first][j] = 'X';
                }
            } else {
                // Same column, fill the cells in between
                for (int k = emptyCells[i - 1].first + 1; k < emptyCells[i].first; k++) {
                    grid[k][emptyCells[i].second] = 'X';
                }
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<string> grid(n);
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }

        connectEmptyCells(grid, n, m);

        for (int i = 0; i < n; i++) {
            cout << grid[i] << endl;
        }
    }

    return 0;
}