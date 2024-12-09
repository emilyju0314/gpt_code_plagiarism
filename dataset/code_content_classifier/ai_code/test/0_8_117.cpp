#include <iostream>
#include <vector>
#include <string>

using namespace std;

void checkCell(vector<string>& grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '#') {
        return;
    }

    if (grid[i][j] == '.') {
        grid[i][j] = '+';
        checkCell(grid, i - 1, j);
        checkCell(grid, i + 1, j);
        checkCell(grid, i, j - 1);
        checkCell(grid, i, j + 1);
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<string> grid(n);
        int lab_i, lab_j;

        for (int i = 0; i < n; i++) {
            cin >> grid[i];
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'L') {
                    lab_i = i;
                    lab_j = j;
                }
            }
        }

        checkCell(grid, lab_i, lab_j);

        for (int i = 0; i < n; i++) {
            cout << grid[i] << endl;
        }
    }

    return 0;
}