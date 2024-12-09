#include <iostream>
#include <vector>

using namespace std;

bool isSameColor(vector<string>& grid, int i, int j) {
    if (i-1 >= 0 && grid[i-1][j] == grid[i][j]) return true;
    if (i+1 < grid.size() && grid[i+1][j] == grid[i][j]) return true;
    if (j-1 >= 0 && grid[i][j-1] == grid[i][j]) return true;
    if (j+1 < grid[i].size() && grid[i][j+1] == grid[i][j]) return true;
    return false;
}

int main() {
    int n, m, t;
    cin >> n >> m >> t;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    for (int k = 0; k < t; k++) {
        int i, j, p;
        cin >> i >> j >> p;
        i--; j--;

        if (p % 2 == 1) {
            cout << grid[i][j] << endl;
        } else {
            if (isSameColor(grid, i, j)) {
                cout << 1 - (grid[i][j] - '0') << endl;
            } else {
                cout << grid[i][j] << endl;
            }
        }
    }

    return 0;
}