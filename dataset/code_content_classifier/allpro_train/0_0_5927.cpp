#include <iostream>
#include <vector>

using namespace std;

bool canCover(vector<vector<char>>& grid, int n, int m, int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != '.') {
        return false;
    }
    grid[i][j] = '*'; // mark the cell as covered
    return true;
}

bool coverGrid(vector<vector<char>>& grid, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                if (!canCover(grid, n, m, i, j+1) && !canCover(grid, n, m, i+1, j)) {
                    return false; // unable to cover the empty cell
                }
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    if (!coverGrid(grid, n, m)) {
        cout << "Not unique" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '.') {
                    if (j+1 < m && grid[i][j+1] == '.') {
                        cout << "<>";
                        j++;
                    } else {
                        cout << "^v";
                    }
                } else {
                    cout << grid[i][j];
                }
            }
            cout << endl;
        }
    }

    return 0;
}