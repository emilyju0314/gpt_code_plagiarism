#include <iostream>
#include <vector>
#include <string>

using namespace std;

void checkAndReplace(vector<string>& grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '#' || grid[i][j] == '+') {
        return;
    }

    grid[i][j] = '+';

    checkAndReplace(grid, i+1, j);
    checkAndReplace(grid, i-1, j);
    checkAndReplace(grid, i, j+1);
    checkAndReplace(grid, i, j-1);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> grid(n);

        int lab_row = -1, lab_col = -1;

        for (int i = 0; i < n; ++i) {
            cin >> grid[i];
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 'L') {
                    lab_row = i;
                    lab_col = j;
                }
            }
        }

        checkAndReplace(grid, lab_row, lab_col);

        for (int i = 0; i < n; ++i) {
            cout << grid[i] << endl;
        }
    }

    return 0;
}